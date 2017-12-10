package com.project.cst337.myapplication;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.io.OutputStream;
import java.lang.reflect.Method;
import java.util.UUID;

public class MainActivity extends Activity {
    private static final String TAG = "bluetooth1";

    Button btnOn, btnOff;
    public TextView textView;
    public EditText morseText;
    public String temp;

    private BluetoothAdapter btAdapter = null;
    private BluetoothSocket btSocket = null;
    private OutputStream outStream = null;

    // SPP UUID service
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    // MAC-address of Bluetooth module (you must edit this line)
    private static String address = "20:16:12:12:72:10";

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);

        btnOn = (Button) findViewById(R.id.btnOn);

        morseText = (EditText) findViewById(R.id.text);
        textView = (TextView) findViewById(R.id.morse);

        btAdapter = BluetoothAdapter.getDefaultAdapter();
        checkBTState();

        btnOn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                String tem12p = morseText.getText().toString();
                sendData(tem12p);
                String temp12 = "morse code: ";
                char ch[] = tem12p.toCharArray();
                for (int i = 0; i < tem12p.length(); i++) {
                    temp12 += charToMorse(ch[i]);
                }
                Toast.makeText(getBaseContext(), "Turn on LED", Toast.LENGTH_SHORT).show();
                textView.setText(temp12);
            }
        });
    }
//        for(int i=0; i<temp.length();i++)
//        {
//
//        }



    private BluetoothSocket createBluetoothSocket(BluetoothDevice device) throws IOException {
        if(Build.VERSION.SDK_INT >= 10){
            try {
                final Method m = device.getClass().getMethod("createInsecureRfcommSocketToServiceRecord", new Class[] { UUID.class });
                return (BluetoothSocket) m.invoke(device, MY_UUID);
            } catch (Exception e) {
                Log.e(TAG, "Could not create Insecure RFComm Connection",e);
            }
        }
        return  device.createRfcommSocketToServiceRecord(MY_UUID);
    }

    @Override
    public void onResume() {
        super.onResume();
        //address = intent.getStringExtra(Bluetooth.EXTRA_DEVICE_ADDRESS);
        Log.d(TAG, "...onResume - try connect...");
        Intent intent = getIntent();
        // Set up a pointer to the remote node using it's address.
        BluetoothDevice device = btAdapter.getRemoteDevice(address);

        // Two things are needed to make a connection:
        //   A MAC address, which we got above.
        //   A Service ID or UUID.  In this case we are using the
        //     UUID for SPP.

        try {
            btSocket = createBluetoothSocket(device);
        } catch (IOException e1) {
            errorExit("Fatal Error", "In onResume() and socket create failed: " + e1.getMessage() + ".");
        }

        // Discovery is resource intensive.  Make sure it isn't going on
        // when you attempt to connect and pass your message.
        btAdapter.cancelDiscovery();

        // Establish the connection.  This will block until it connects.
        Log.d(TAG, "...Connecting...");
        try {
            btSocket.connect();
            Log.d(TAG, "...Connection ok...");
        } catch (IOException e) {
            try {
                btSocket.close();
            } catch (IOException e2) {
                errorExit("Fatal Error", "In onResume() and unable to close socket during connection failure" + e2.getMessage() + ".");
            }
        }

        // Create a data stream so we can talk to server.
        Log.d(TAG, "...Create Socket...");

        try {
            outStream = btSocket.getOutputStream();
        } catch (IOException e) {
            errorExit("Fatal Error", "In onResume() and output stream creation failed:" + e.getMessage() + ".");
        }
    }

    @Override
    public void onPause() {
        super.onPause();

        Log.d(TAG, "...In onPause()...");

        if (outStream != null) {
            try {
                outStream.flush();
            } catch (IOException e) {
                errorExit("Fatal Error", "In onPause() and failed to flush output stream: " + e.getMessage() + ".");
            }
        }

        try     {
            btSocket.close();
        } catch (IOException e2) {
            errorExit("Fatal Error", "In onPause() and failed to close socket." + e2.getMessage() + ".");
        }
    }

    private void checkBTState() {
        // Check for Bluetooth support and then check to make sure it is turned on
        // Emulator doesn't support Bluetooth and will return null
        if(btAdapter==null) {
            errorExit("Fatal Error", "Bluetooth not support");
        } else {
            if (btAdapter.isEnabled()) {
                Log.d(TAG, "...Bluetooth ON...");
            } else {
                //Prompt user to turn on Bluetooth
                Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enableBtIntent, 1);
            }
        }
    }

    private void errorExit(String title, String message){
        Toast.makeText(getBaseContext(), title + " - " + message, Toast.LENGTH_LONG).show();
        finish();
    }

    private void sendData(String message) {
        byte[] msgBuffer = message.getBytes();

        Log.d(TAG, "...Send data: " + message + "...");

        try {
            outStream.write(msgBuffer);
        } catch (IOException e) {
            String msg = "In onResume() and an exception occurred during write: " + e.getMessage();
            if (address.equals("00:00:00:00:00:00"))
                msg = msg + ".\n\nUpdate your server address from 00:00:00:00:00:00 to the correct address on line 35 in the java code";
            msg = msg +  ".\n\nCheck that the SPP UUID: " + MY_UUID.toString() + " exists on server.\n\n";

            errorExit("Fatal Error", msg);
        }
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
