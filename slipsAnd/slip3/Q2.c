//MainActivity.java

package com.example.studentapp;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class MainActivity extends AppCompatActivity {
    EditText etName, etSurname, etClass, etMarks;
    RadioGroup rgGender;
    CheckBox cbReading, cbSports, cbMusic;
    Button btnSubmit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etName = findViewById(R.id.et_name);
        etSurname = findViewById(R.id.et_surname);
        etClass = findViewById(R.id.et_class);
        etMarks = findViewById(R.id.et_marks);
        rgGender = findViewById(R.id.rg_gender);
        cbReading = findViewById(R.id.cb_reading);
        cbSports = findViewById(R.id.cb_sports);
        cbMusic = findViewById(R.id.cb_music);
        btnSubmit = findViewById(R.id.btn_submit);

        btnSubmit.setOnClickListener(v -> {
            // Get Values
            String name = etName.getText().toString();
            String surname = etSurname.getText().toString();
            String studentClass = etClass.getText().toString();
            String marks = etMarks.getText().toString();

            // Get Selected Gender
            int selectedGenderId = rgGender.getCheckedRadioButtonId();
            RadioButton selectedGender = findViewById(selectedGenderId);
            String gender = (selectedGender != null) ? selectedGender.getText().toString() : "Not Specified";

            // Get Hobbies
            StringBuilder hobbies = new StringBuilder();
            if (cbReading.isChecked()) hobbies.append("Reading ");
            if (cbSports.isChecked()) hobbies.append("Sports ");
            if (cbMusic.isChecked()) hobbies.append("Music ");

            // Send Data to Next Activity
            Intent intent = new Intent(MainActivity.this, MainActivity2.class);
            intent.putExtra("name", name);
            intent.putExtra("surname", surname);
            intent.putExtra("class", studentClass);
            intent.putExtra("gender", gender);
            intent.putExtra("hobbies", hobbies.toString());
            intent.putExtra("marks", marks);
            startActivity(intent);
        });
    }
}

//activity_main.xml

<?xml version="1.0" encoding="utf-8"?>
<ScrollView xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        android:padding="20dp">

        <!-- Name -->
        <EditText
            android:id="@+id/et_name"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Enter Name"/>

        <!-- Surname -->
        <EditText
            android:id="@+id/et_surname"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Enter Surname"/>

        <!-- Class -->
        <EditText
            android:id="@+id/et_class"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Enter Class"/>

        <!-- Gender (Radio Buttons) -->
        <RadioGroup
            android:id="@+id/rg_gender"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:orientation="horizontal">

            <RadioButton
                android:id="@+id/rb_male"
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:text="Male"/>

            <RadioButton
                android:id="@+id/rb_female"
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:text="Female"/>
        </RadioGroup>

        <!-- Hobbies (Checkbox) -->
        <CheckBox
            android:id="@+id/cb_reading"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Reading"/>
        <CheckBox
            android:id="@+id/cb_sports"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Sports"/>
        <CheckBox
            android:id="@+id/cb_music"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Music"/>

        <!-- Marks -->
        <EditText
            android:id="@+id/et_marks"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:hint="Enter Marks"
            android:inputType="number"/>

        <!-- Submit Button -->
        <Button
            android:id="@+id/btn_submit"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:text="Submit"
            android:layout_marginTop="20dp"/>
    </LinearLayout>
</ScrollView>

//MainActivity2.java

package com.example.studentapp;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        // Get Data from Intent
        String name = getIntent().getStringExtra("name");
        String surname = getIntent().getStringExtra("surname");
        String studentClass = getIntent().getStringExtra("class");
        String gender = getIntent().getStringExtra("gender");
        String hobbies = getIntent().getStringExtra("hobbies");
        String marks = getIntent().getStringExtra("marks");

        // Set Data to TextViews
        ((TextView) findViewById(R.id.tv_name)).setText(name);
        ((TextView) findViewById(R.id.tv_surname)).setText(surname);
        ((TextView) findViewById(R.id.tv_class)).setText(studentClass);
        ((TextView) findViewById(R.id.tv_gender)).setText(gender);
        ((TextView) findViewById(R.id.tv_hobbies)).setText(hobbies);
        ((TextView) findViewById(R.id.tv_marks)).setText(marks);
    }
}


//activity_main2.xml

<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="20dp">

    <TableLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:stretchColumns="1">

        <TableRow>
            <TextView android:text="Name:" />
            <TextView android:id="@+id/tv_name" />
        </TableRow>

        <TableRow>
            <TextView android:text="Surname:" />
            <TextView android:id="@+id/tv_surname" />
        </TableRow>

        <TableRow>
            <TextView android:text="Class:" />
            <TextView android:id="@+id/tv_class" />
        </TableRow>

        <TableRow>
            <TextView android:text="Gender:" />
            <TextView android:id="@+id/tv_gender" />
        </TableRow>

        <TableRow>
            <TextView android:text="Hobbies:" />
            <TextView android:id="@+id/tv_hobbies" />
        </TableRow>

        <TableRow>
            <TextView android:text="Marks:" />
            <TextView android:id="@+id/tv_marks" />
        </TableRow>
    </TableLayout>
</LinearLayout>

