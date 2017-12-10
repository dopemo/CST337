package com.project.cst337.myapplication;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;

import java.io.IOException;
import java.util.UUID;

/**
 * Created by Mohamad on 12/9/2017.
 */

public class ConnectThread extends Thread {
    private final BluetoothSocket mmSocket;
    private final BluetoothDevice mmDevice;
   ;
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");
    public ConnectedThread mConnectedThread;
    public ConnectThread(BluetoothDevice device) {
        BluetoothSocket tmp = null;
        mmDevice = device;
        try {
            tmp = device.createRfcommSocketToServiceRecord(MY_UUID);
        } catch (IOException e) { }
        mmSocket = tmp;
    }
    public void run() {

        //mBluetoothAdapter.cancelDiscovery();
        try {
            mmSocket.connect();
        } catch (IOException connectException) {
            try {
                mmSocket.close();
            } catch (IOException closeException) { }
            return;
        }
        mConnectedThread = new ConnectedThread(mmSocket);
        mConnectedThread.start();
    }
    public void cancel() {
        try {
            mmSocket.close();
        } catch (IOException e) { }
    }
}