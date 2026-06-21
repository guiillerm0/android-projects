package com.example.movlilesparcial1;


import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;

public class SelectionActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.selection_activity);

        Button buttonA5 = findViewById(R.id.button_a5_);
        Button buttonA6 = findViewById(R.id.button_a6_);
        Button buttonB0 = findViewById(R.id.button_b0_);

        // Asignar acciones a los botones
        buttonA5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(SelectionActivity.this, A5.class);
                startActivity(intent);
            }
        });

        buttonA6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intenta6 = new Intent(SelectionActivity.this, A6.class);
                startActivity(intenta6);
            }
        });

        buttonB0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intentb0 = new Intent(SelectionActivity.this, B0.class);
                startActivity(intentb0);

            }
        });
    }
}

