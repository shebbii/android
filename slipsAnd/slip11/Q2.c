//MainActivity.java
package com.example.slip11_2;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private EditText etFirstName, etMiddleName, etLastName, etDob, etAddress, etEmail;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize UI Elements
        etFirstName = findViewById(R.id.etFirstName);
        etMiddleName = findViewById(R.id.etMiddleName);
        etLastName = findViewById(R.id.etLastName);
        etDob = findViewById(R.id.etDob);
        etAddress = findViewById(R.id.etAddress);
        etEmail = findViewById(R.id.etEmail);
        Button btnSubmit = findViewById(R.id.btnSubmit);

        // Submit Button Click Listener
        btnSubmit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Get input values
                String firstName = etFirstName.getText().toString();
                String middleName = etMiddleName.getText().toString();
                String lastName = etLastName.getText().toString();
                String dob = etDob.getText().toString();
                String address = etAddress.getText().toString();
                String email = etEmail.getText().toString();

                // Start Second Activity with Intent and send data
                Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                intent.putExtra("FIRST_NAME", firstName);
                intent.putExtra("MIDDLE_NAME", middleName);
                intent.putExtra("LAST_NAME", lastName);
                intent.putExtra("DOB", dob);
                intent.putExtra("ADDRESS", address);
                intent.putExtra("EMAIL", email);
                startActivity(intent);
            }
        });
    }
}
//activity_main.xml
<?xml version="1.0" encoding="utf-8"?>
<ScrollView xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:padding="20dp">

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        android:gravity="center">

        <EditText
            android:id="@+id/etFirstName"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="First Name"/>

        <EditText
            android:id="@+id/etMiddleName"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Middle Name"/>

        <EditText
            android:id="@+id/etLastName"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Last Name"/>

        <EditText
            android:id="@+id/etDob"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Date of Birth (DD/MM/YYYY)"/>

        <EditText
            android:id="@+id/etAddress"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Address"/>

        <EditText
            android:id="@+id/etEmail"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Email ID"
            android:inputType="textEmailAddress"/>

        <Button
            android:id="@+id/btnSubmit"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Submit"/>

    </LinearLayout>
</ScrollView>

//SecondActivity.java
package com.example.slip11_2;

import android.os.Bundle;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        // Initialize TextView
        TextView tvStudentInfo = findViewById(R.id.tvStudentInfo);

        // Retrieve Data from Intent
        String firstName = getIntent().getStringExtra("FIRST_NAME");
        String middleName = getIntent().getStringExtra("MIDDLE_NAME");
        String lastName = getIntent().getStringExtra("LAST_NAME");
        String dob = getIntent().getStringExtra("DOB");
        String address = getIntent().getStringExtra("ADDRESS");
        String email = getIntent().getStringExtra("EMAIL");

        // Display Student Details
        String studentInfo = "Name: " + firstName + " " + middleName + " " + lastName +
                "\nDate of Birth: " + dob +
                "\nAddress: " + address +
                "\nEmail: " + email;

        tvStudentInfo.setText(studentInfo);
    }
}
//activity_second.xml
<?xml version="1.0" encoding="utf-8"?>
<ScrollView xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:padding="20dp">

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        android:gravity="center">

        <TextView
            android:id="@+id/tvStudentInfo"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:textSize="18sp"
            android:textStyle="bold"
            android:padding="10dp"/>

    </LinearLayout>
</ScrollView>

