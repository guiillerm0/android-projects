package com.example.movlilesparcial1;

import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;

public class A6 extends AppCompatActivity {

    private MediaPlayer mediaPlayer;
    private Button playPauseButton;
    private Button volumeUpButton;
    private Button volumeDownButton;
    private AudioManager audioManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_a6);

        // Inicializar los botones
        playPauseButton = findViewById(R.id.button_ini_a6);
        volumeUpButton = findViewById(R.id.button_volume2_a6);
        volumeDownButton = findViewById(R.id.button_volume1_a6);

        // Inicializar el reproductor de audio
        mediaPlayer = MediaPlayer.create(this, R.raw.audio_a6);

        // Inicializar AudioManager
        audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);

        // Listener para el botón de iniciar/pausar
        playPauseButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (mediaPlayer.isPlaying()) {
                    mediaPlayer.pause();
                    playPauseButton.setText("PlayB0");
                } else {
                    mediaPlayer.start();
                    playPauseButton.setText("PauseB0");
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
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        // Liberar recursos del reproductor de audio cuando la actividad se destruye
        if (mediaPlayer != null) {
            mediaPlayer.release();
            mediaPlayer = null;
        }
    }
}
