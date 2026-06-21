package com.example.movlilesparcial1;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.pm.PackageManager;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;

public class B0 extends AppCompatActivity {

    private MediaPlayer mediaPlayer;
    private Button playPauseButton;
    private Button volumeUpButton;
    private Button volumeDownButton;
    private AudioManager audioManager;
    private BluetoothAdapter btAdapter = null;
    private BluetoothSocket btSocket = null;
    private StringBuilder DataStringIN = new StringBuilder();
    private ConnectedThread MyConexionBT;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_a5);

        // Inicializar los botones
        playPauseButton = findViewById(R.id.button_ini_b0);
        volumeUpButton = findViewById(R.id.button_volume2_b0);
        volumeDownButton = findViewById(R.id.button_volume1_b0);

        // Inicializar el reproductor de audio
        mediaPlayer = MediaPlayer.create(this, R.raw.audio_a5);

        // Inicializar AudioManager
        audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);

        // Listener para el botón de iniciar/pausar
        playPauseButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (mediaPlayer.isPlaying()) {
                    mediaPlayer.pause();
                    playPauseButton.setText("Play");
                    if (MyConexionBT != null) {
                        MyConexionBT.write("playa5"); // Enviar comando de pausa al Arduino
                    }
                } else {
                    mediaPlayer.start();
                    playPauseButton.setText("Pause");
                    if (MyConexionBT != null) {
                        MyConexionBT.write("Pausea5"); // Enviar comando de play al Arduino
                    }
                }
            }
        });

        // Listener para el botón de subir volumen
        volumeUpButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                audioManager.adjustVolume(AudioManager.ADJUST_RAISE, AudioManager.FLAG_PLAY_SOUND);
            }
        });

        // Listener para el botón de bajar volumen
        volumeDownButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                audioManager.adjustVolume(AudioManager.ADJUST_LOWER, AudioManager.FLAG_PLAY_SOUND);
            }
        });

        // Establecer conexión Bluetooth con el Arduino
        connectToArduino();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        // Liberar recursos del reproductor de audio cuando la actividad se destruye
        if (mediaPlayer != null) {
            mediaPlayer.release();
            mediaPlayer = null;
        }
        // Cerrar la conexión Bluetooth
        if (MyConexionBT != null) {
            MyConexionBT.cancel();
        }
    }

    // Método para establecer la conexión Bluetooth con el Arduino
    private void connectToArduino() {
        BluetoothDevice device = btAdapter.getRemoteDevice("00:00:00:00:00:00"); // Dirección MAC del Arduino
        UUID uuid = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB"); // UUID para SPP
        try {
            if (ActivityCompat.checkSelfPermission(this, android.Manifest.permission.BLUETOOTH_CONNECT) != PackageManager.PERMISSION_GRANTED) {
                // TODO: Consider calling
                //    ActivityCompat#requestPermissions
                // here to request the missing permissions, and then overriding
                //   public void onRequestPermissionsResult(int requestCode, String[] permissions,
                //                                          int[] grantResults)
                // to handle the case where the user grants the permission. See the documentation
                // for ActivityCompat#requestPermissions for more details.
                return;
            }
            btSocket = device.createRfcommSocketToServiceRecord(uuid);
            btSocket.connect();
            MyConexionBT = new ConnectedThread(btSocket);
            MyConexionBT.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Clase para manejar la conexión Bluetooth
    private class ConnectedThread extends Thread {
        private final InputStream mmInStream;
        private final OutputStream mmOutStream;

        public ConnectedThread(BluetoothSocket socket) {
            InputStream tmpIn = null;
            OutputStream tmpOut = null;
            try {
                tmpIn = socket.getInputStream();
                tmpOut = socket.getOutputStream();
            } catch (IOException e) {
                e.printStackTrace();
            }
            mmInStream = tmpIn;
            mmOutStream = tmpOut;
        }

        public void run() {
            byte[] buffer = new byte[256];
            int bytes;
            while (true) {
                try {
                    bytes = mmInStream.read(buffer);
                    String readMessage = new String(buffer, 0, bytes);
                    // Do something with the received message
                } catch (IOException e) {
                    e.printStackTrace();
                    break;
                }
            }
        }

        public void write(String input) {
            try {
                mmOutStream.write(input.getBytes());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        public void cancel() {
            try {
                btSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
