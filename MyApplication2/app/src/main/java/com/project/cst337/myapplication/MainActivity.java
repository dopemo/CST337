

package com.project.cst337.myapplication;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    public Button button;
    public TextView morseCode;
    public EditText u_input;
    public String user_input;
    public String morse1="morse code: ";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button=(Button)findViewById(R.id.submit);
        morseCode=(TextView)findViewById(R.id.morse);
        u_input=(EditText)findViewById(R.id.input);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                user_input=u_input.getText().toString();
                char[] ch=user_input.toCharArray();
                for(int i=0;i<user_input.length();i++)
                {
                    morse1+=charToMorse(ch[i]);
                }
                morseCode.setText(morse1);
//                u_input.setText(morse1);
            }
        });




    }

    private String charToMorse(char c) {
        switch(c) {
            case 'a': case 'A':
                return ".-";
            case 'b': case 'B':
                return "-...";
            case 'c': case 'C':
                return "-.-.";
            case 'd': case 'D':
                return "--..";
            case 'e': case 'E':
                return ".";
            case 'f': case 'F':
                return "..-.";
            case 'g': case 'G':
                return "--.";
            case 'h': case 'H':
                return "....";
            case 'i': case 'I':
                return "..";
            case 'j': case 'J':
                return ".---";
            case 'k': case 'K':
                return "-.-";
            case 'l': case 'L':
                return ".-..";
            case 'm': case 'M':
                return "--";
            case 'n': case 'N':
                return "-.";
            case 'o': case 'O':
                return "---";
            case 'p': case 'P':
                return ".--.";
            case 'q': case 'Q':
                return "--.-";
            case 'r': case 'R':
                return ".-.";
            case 's': case 'S':
                return "...";
            case 't': case 'T':
                return "-";
            case 'u': case 'U':
                return "..-";
            case 'v': case 'V':
                return "...-";
            case 'w': case 'W':
                return ".--";
            case 'x': case 'X':
                return "-..-";
            case 'y': case 'Y':
                return "-.--";
            case 'z': case 'Z':
                return "--..";
            case '0':
                return "-----";
            case '1':
                return ".----";
            case '2':
                return "..---";
            case '3':
                return "...--";
            case '4':
                return "....-";
            case '5':
                return ".....";
            case '6':
                return "-....";
            case '7':
                return "--...";
            case '8':
                return "---..";
            case '9':
                return "----.";
            case '.':
                return ".-.-.-";
            case '?':
                return "..--..";
            case ',':
                return "--..--";
            case ' ':
                return " ";
            default:
                return "";
        }

    }
}
