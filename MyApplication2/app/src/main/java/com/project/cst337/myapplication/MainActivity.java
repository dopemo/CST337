

package com.project.cst337.myapplication;

        import android.support.v7.app.AppCompatActivity;
        import android.os.Bundle;
        import android.view.View;
        import android.util.Log;
        import android.widget.EditText;
        import android.widget.TextView;
        import android.content.Intent;
public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        View translateButton=findViewById(R.id.translate);
        /* gets the calculate button from xml*/
        translateButton.setOnClickListener(this);
        /*when button is clicked*/

    }

    @Override
    public void onClick(View view){
        EditText cinput;
        String input;
        TextView result;
        Class nextActivity=null;

        if(view.getId()==R.id.translate){
            cinput=(EditText)findViewById(R.id.cinput_edittext); //if buttons clicked
            input=cinput.getText().toString(); //get text to string
            nextActivity=TextToMorse.class;
            break;
        }
        Intent intent=new Intent(this,nextActivity);
        startActivity(intent);

    }
