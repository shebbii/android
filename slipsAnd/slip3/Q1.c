//java file

package com.example.firstandroidproject;

import androidx.appcompat.app.AppCompatActivity;
import android.graphics.Color;
import android.graphics.Typeface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView collage_name = findViewById(R.id.collage_name);
        Button change_button = findViewById(R.id.change_button);

        change_button.setOnClickListener(v -> {
            collage_name.setTextColor(Color.BLUE);
            collage_name.setTextSize(30);
            collage_name.setTypeface(null, Typeface.BOLD_ITALIC);
        });
    }
}

//xml file

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:gravity="center">

    <!-- College Name TextView -->
    <TextView
        android:id="@+id/collage_name"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="S.M Joshi College"
        android:textSize="24sp"
        android:textStyle="bold"
        android:textColor="#000000"
        android:layout_marginBottom="20dp"/>

    <!-- Push Button -->
    <Button
        android:id="@+id/change_button"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Push"/>

</LinearLayout>


