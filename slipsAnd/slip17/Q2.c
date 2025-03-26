//xml file
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    android:padding="20dp"
    android:gravity="center">

    <!-- Input Field for Number -->
    <EditText
        android:id="@+id/numberInput"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:hint="Enter a number"
        android:inputType="number"
        android:padding="10dp"
        android:textSize="18sp" />

    <!-- TextView to Show Result -->
    <TextView
        android:id="@+id/resultText"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="Result will be displayed here"
        android:textSize="18sp"
        android:gravity="center"
        android:padding="20dp"
        android:textColor="#000000"/>

</LinearLayout>

//java file
package com.example.slip20_2;

import android.os.Bundle;
import android.view.ContextMenu;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    EditText numberInput;
    TextView resultText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        numberInput = findViewById(R.id.numberInput);
        resultText = findViewById(R.id.resultText);

        // Register the EditText for context menu
        registerForContextMenu(numberInput);
    }

    // Create Context Menu
    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);
        menu.setHeaderTitle("Choose an Operation");
        menu.add(Menu.NONE, 1, Menu.NONE, "Calculate Factorial");
        menu.add(Menu.NONE, 2, Menu.NONE, "Calculate Sum of Digits");
    }

    // Handle Context Menu Selection
    @Override
    public boolean onContextItemSelected(@NonNull MenuItem item) {
        String input = numberInput.getText().toString();

        if (input.isEmpty()) {
            Toast.makeText(this, "Please enter a number!", Toast.LENGTH_SHORT).show();
            return false;
        }

        int number = Integer.parseInt(input);

        switch (item.getItemId()) {
            case 1:
                resultText.setText("Factorial: " + calculateFactorial(number));
                return true;

            case 2:
                resultText.setText("Sum of Digits: " + sumOfDigits(number));
                return true;

            default:
                return super.onContextItemSelected(item);
        }
    }

    // Function to Calculate Factorial
    private long calculateFactorial(int num) {
        long fact = 1;
        for (int i = 1; i <= num; i++) {
            fact *= i;
        }
        return fact;
    }

    // Function to Calculate Sum of Digits
    private int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}

