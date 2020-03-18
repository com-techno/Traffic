package ru.techno.traffic;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import androidx.annotation.Nullable;

import java.util.Calendar;

public class SolveActivity extends Activity {
    float fMaxBalance;
    LinearLayout warning;
    Button buttonSolve;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_solve);
        fMaxBalance = getMaxBalance();
        warning = findViewById(R.id.solve_msg);
        buttonSolve = findViewById(R.id.solve_button);
        ((EditText) findViewById(R.id.solve_et)).addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {

            }

            @Override
            public void afterTextChanged(Editable s) {
                fMaxBalance = getMaxBalance();
                if (Float.parseFloat(s.toString()) > fMaxBalance){
                    warning.setVisibility(View.VISIBLE);
                    buttonSolve.setVisibility(View.GONE);
                } else {
                    warning.setVisibility(View.GONE);
                    buttonSolve.setVisibility(View.VISIBLE);
                }
            }
        });

        buttonSolve.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

            }
        });
    }

    void solveAndPrint() {


    }

    float getMaxBalance() {
        return getApplicationContext()
                .getSharedPreferences("balance", Context.MODE_PRIVATE)
                .getFloat("max_balance", 0.f);
    }
}

/*
    final Calendar calendar = Calendar.getInstance();
    int iDate = calendar.get(Calendar.HOUR_OF_DAY) < 20 ? calendar.get(Calendar.DATE) : calendar.get(Calendar.DATE) + 1;
    int iMonth = calendar.get(Calendar.YEAR) % 4 == 0 && calendar.get(Calendar.MONTH) == Calendar.FEBRUARY ? 13 : calendar.get(Calendar.MONTH);
                Log.i("Calendar/date", String.valueOf(calendar.get(Calendar.DATE)));
                        Log.i("Calendar/month", String.valueOf(calendar.get(Calendar.MONTH)));
                        Log.i("Calendar/year", String.valueOf(calendar.get(Calendar.YEAR)));
                        Log.i("Calendar/hourOfDay", String.valueOf(calendar.get(Calendar.HOUR_OF_DAY)));*/
