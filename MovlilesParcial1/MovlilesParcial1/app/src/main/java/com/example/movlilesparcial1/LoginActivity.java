package com.example.movlilesparcial1;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class LoginActivity extends AppCompatActivity {

    //Establecimiento de usuario y contraseña
    private static String PREFS_NAME;
    private static String KEY_USUARIO;
    private static String KEY_CONTRASENA;

    private EditText editTextUsuario;
    private EditText editTextContrasena;
    private Button buttonIniciarSesion;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        PREFS_NAME = getResources().getString(R.string.prefs_name);
        KEY_USUARIO = getResources().getString(R.string.key_usuario);
        KEY_CONTRASENA = getResources().getString(R.string.key_contrasena);

        editTextUsuario = findViewById(R.id.editUser);
        editTextContrasena = findViewById(R.id.editTextPass);
        buttonIniciarSesion = findViewById(R.id.buttonIniciarSesion);

        buttonIniciarSesion.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String usuario = editTextUsuario.getText().toString();
                String contrasena = editTextContrasena.getText().toString();

                // Verificar si el usuario y la contraseña coinciden con los guardados en SharedPreferences
                if (verificarUsuarioContrasena(usuario, contrasena)) {
                    // Si coinciden, iniciar la actividad de selección
                    Intent intent = new Intent(LoginActivity.this, DispositivosVinculados.class);
                    startActivity(intent);
                } else {
                    // Si no coinciden, mostrar un mensaje de error
                    Toast.makeText(LoginActivity.this, "Usuario o contraseña incorrectos", Toast.LENGTH_SHORT).show();
                    mostrarDatosSharedPreferences();
                }

                // Mostrar los datos almacenados en SharedPreferences en un Toast
                mostrarDatosSharedPreferences();
            }
        });
    }

    // Método para verificar si el usuario y la contraseña coinciden con los guardados en SharedPreferences
    private boolean verificarUsuarioContrasena(String usuario, String contrasena) {
        SharedPreferences prefs = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        String usuarioGuardado = prefs.getString(KEY_USUARIO, "");
        String contrasenaGuardada = prefs.getString(KEY_CONTRASENA, "");
        return usuario.equals(usuarioGuardado) && contrasena.equals(contrasenaGuardada);
    }

    // Método para mostrar los datos almacenados en SharedPreferences en un Toast
    private void mostrarDatosSharedPreferences() {
        SharedPreferences prefs = getSharedPreferences(PREFS_NAME, MODE_PRIVATE);
        String usuarioGuardado = prefs.getString(KEY_USUARIO, "");
        String contrasenaGuardada = prefs.getString(KEY_CONTRASENA, "");

        String mensaje =  usuarioGuardado + "\n" + contrasenaGuardada;
        Toast.makeText(LoginActivity.this, mensaje, Toast.LENGTH_LONG).show();
    }
}
