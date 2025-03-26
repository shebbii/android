//java file

package com.example.slip13_2;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    EditText locationInput;
    Button searchButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        locationInput = findViewById(R.id.locationInput);
        searchButton = findViewById(R.id.searchButton);

        searchButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String location = locationInput.getText().toString().trim();

                if (!location.isEmpty()) {
                    Uri mapUri = Uri.parse("geo:0,0?q=" + Uri.encode(location));
                    Intent mapIntent = new Intent(Intent.ACTION_VIEW, mapUri);
                    mapIntent.setPackage("com.google.android.apps.maps");

                    if (mapIntent.resolveActivity(getPackageManager()) != null) {
                        startActivity(mapIntent);
                    } else {
                        // Agar Google Maps installed nahi hai toh browser me open karo
                        Uri browserUri = Uri.parse("https://www.google.com/maps/search/" + Uri.encode(location));
                        Intent browserIntent = new Intent(Intent.ACTION_VIEW, browserUri);
                        startActivity(browserIntent);
                    }
                } else {
                    Toast.makeText(MainActivity.this, "Please enter a location!", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}

//xml file
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="20dp">

    <EditText
        android:id="@+id/locationInput"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:hint="Enter location"
        android:inputType="text" />

    <Button
        android:id="@+id/searchButton"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="Search on Google Maps"
        android:layout_marginTop="10dp"/>

</LinearLayout>
//manifest
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools">

    <application
        android:allowBackup="true"
        android:dataExtractionRules="@xml/data_extraction_rules"
        android:fullBackupContent="@xml/backup_rules"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:roundIcon="@mipmap/ic_launcher_round"
        android:supportsRtl="true"
        android:theme="@style/Theme.Slip13_2"
        tools:targetApi="31">
        <activity
            android:name=".MainActivity"
            android:exported="true">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>

</manifest>
