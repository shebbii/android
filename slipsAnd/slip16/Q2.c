//xml file
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:gravity="center"
    android:orientation="vertical"
    android:padding="20dp">

    <Button
        android:id="@+id/btnSelectTime"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Select Time" />

    <TextView
        android:id="@+id/tvSelectedTime"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Selected Time: "
        android:textSize="18sp"
        android:layout_marginTop="20dp"/>
</LinearLayout>
//java file
package com.example.timepickerdemo;

import android.app.TimePickerDialog;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.TimePicker;

import androidx.appcompat.app.AppCompatActivity;

import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    Button btnSelectTime;
    TextView tvSelectedTime;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnSelectTime = findViewById(R.id.btnSelectTime);
        tvSelectedTime = findViewById(R.id.tvSelectedTime);

        btnSelectTime.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Get the current time
                Calendar calendar = Calendar.getInstance();
                int hour = calendar.get(Calendar.HOUR_OF_DAY);
                int minute = calendar.get(Calendar.MINUTE);

                // Create a TimePickerDialog
                TimePickerDialog timePickerDialog = new TimePickerDialog(
                        MainActivity.this,
                        new TimePickerDialog.OnTimeSetListener() {
                            @Override
                            public void onTimeSet(TimePicker view, int selectedHour, int selectedMinute) {
                                // Display the selected time
                                tvSelectedTime.setText("Selected Time: " + selectedHour + ":" + selectedMinute);
                            }
                        }, hour, minute, true);
                
                // Show the TimePicker dialog
                timePickerDialog.show();
            }
        });
    }
}

