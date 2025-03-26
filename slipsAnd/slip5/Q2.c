//MainActivity.java

package com.example.slip5_1;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    Button btnShowDialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnShowDialog = findViewById(R.id.btnShowDialog);

        btnShowDialog.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showFriendDialog();
            }
        });
    }

    private void showFriendDialog() {
        final String[] friends = {"Amit", "Raj", "Priya", "Neha"};

        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Select a Friend");

        builder.setItems(friends, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                String selectedFriend = friends[which];
                Toast.makeText(MainActivity.this, "Hello, " + selectedFriend + "!", Toast.LENGTH_SHORT).show();
            }
        });

        builder.setNegativeButton("Cancel", null);
        AlertDialog dialog = builder.create();
        dialog.show();
    }
}

//activity_main.xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:gravity="center"
    android:padding="20dp">

    <Button
        android:id="@+id/btnShowDialog"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="Show Friends List" />

</LinearLayout>

