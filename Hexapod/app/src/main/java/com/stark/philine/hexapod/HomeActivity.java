package com.stark.philine.hexapod;

import android.Manifest;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.graphics.Color;
import android.os.Build;
import android.support.annotation.RequiresApi;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;

import java.util.ArrayList;

public class HomeActivity extends AppCompatActivity implements AdapterView.OnItemClickListener {

    //REQUEST_ENABLED_BT must be any number greater than 0
    private final static int REQUEST_ENABLE_BT = 1;
    private static final String TAG = "MyActivity";

    BluetoothAdapter mBluetoothAdapter;

    //List for the Devices
    public ArrayList<BluetoothDevice> mBTDevices = new ArrayList<>();
    public DeviceListAdapter mDeviceListAdapter;
    ListView lvNewDevices;

    //Create a BroadcastReceiver for ACTION_FOUND
    private final BroadcastReceiver mBroadcastReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            final String action = intent.getAction();
            Log.d(TAG,"onReceive: ACTION FOUND.");

            if(action.equals(BluetoothDevice.ACTION_FOUND)){
                BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                mBTDevices.add(device);
                Log.d(TAG, "onReceive: " + device.getName()+ ": " + device.getAddress());
                mDeviceListAdapter = new DeviceListAdapter(context, R.layout.device_adapter_view, mBTDevices);
                lvNewDevices.setAdapter(mDeviceListAdapter);
            }
        }
    };


    /**
     * Broadcast Receiver that detects bond state changes (Pairing status changes)
     */
    private final BroadcastReceiver mBroadcastReceiver2 = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            final String action = intent.getAction();

            if(action.equals(BluetoothDevice.ACTION_BOND_STATE_CHANGED)){
                BluetoothDevice mDevice = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                //3 cases:
                //case1: bonded already
                if (mDevice.getBondState() == BluetoothDevice.BOND_BONDED){
                    Log.d(TAG, "BroadcastReceiver: BOND_BONDED.");
                    final Button button_searchNew = (Button)findViewById(R.id.btnSearchNew);
                    button_searchNew.setText("Bonded with a Device!");
                    //Start th new activity with the joystick
                    Intent homeIntent = new Intent(HomeActivity.this, JoystickActivity.class);
                    startActivity(homeIntent);
                    finish();

                }
                //case2: creating a bone
                if (mDevice.getBondState() == BluetoothDevice.BOND_BONDING) {
                    Log.d(TAG, "BroadcastReceiver: BOND_BONDING.");
                    final Button button_searchNew = (Button)findViewById(R.id.btnSearchNew);
                    button_searchNew.setBackgroundColor(Color.parseColor("#FFEB3B"));

                }
                //case3: breaking a bond
                if (mDevice.getBondState() == BluetoothDevice.BOND_NONE) {
                    Log.d(TAG, "BroadcastReceiver: BOND_NONE.");
                }
            }
        }
    };

    //Create a BroadcastReceiver for ACTION_CONNECTED
    private final BroadcastReceiver mBroadcastReceiver3 = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            final String action = intent.getAction();
            Log.d(TAG,"onReceive: ACTION CONNECTED.");

            final Button button_searchNew = (Button)findViewById(R.id.btnSearchNew);

            if(action.equals(BluetoothDevice.ACTION_ACL_CONNECTED)){
                BluetoothDevice device = intent.getParcelableExtra(BluetoothDevice.EXTRA_DEVICE);
                mBTDevices.add(device);
                Log.d(TAG, "onReceive: " + device.getName()+ ": " + device.getAddress());
                mDeviceListAdapter = new DeviceListAdapter(context, R.layout.device_adapter_view, mBTDevices);
                lvNewDevices.setAdapter(mDeviceListAdapter);
                button_searchNew.setText("Connected with: "+ device.getName());

            }

        }
    };


    @Override
    protected void onDestroy(){
        Log.d(TAG, "onDestroy: called.");
        super.onDestroy();
        unregisterReceiver(mBroadcastReceiver);
        unregisterReceiver(mBroadcastReceiver2);
        unregisterReceiver(mBroadcastReceiver3);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.activity_home);

        lvNewDevices = (ListView) findViewById(R.id.lvNewDevices);
        mBTDevices = new ArrayList<>();

        mBluetoothAdapter = BluetoothAdapter.getDefaultAdapter();

        lvNewDevices.setOnItemClickListener(HomeActivity.this);

        IntentFilter filter = new IntentFilter(BluetoothDevice.ACTION_BOND_STATE_CHANGED);
        registerReceiver(mBroadcastReceiver,filter);
        registerReceiver(mBroadcastReceiver2,filter);
        registerReceiver(mBroadcastReceiver3,filter);
        getButtonClicked();




    }

    public void getButtonClicked() {

        final Button button_searchNew = (Button)findViewById(R.id.btnSearchNew);
        button_searchNew.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                enableBluetooth();
                discoveringDevices(mBluetoothAdapter);
            }
        });
    }

    public void enableBluetooth() {

        final Button button_searchNew = (Button)findViewById(R.id.btnSearchNew);
        if (!mBluetoothAdapter.isEnabled()) {
            // This call issues a request to enable Bluetooth through the system settings
            Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(enableBtIntent, REQUEST_ENABLE_BT);
            //set Button to color green
            button_searchNew.setBackgroundColor(Color.parseColor("#4CAF50"));
            button_searchNew.setText("Searching...");
        } else {
            button_searchNew.setText("Already Searching...");
            button_searchNew.setBackgroundColor(Color.parseColor("#4CAF50"));

        }
    }

    public void discoveringDevices(BluetoothAdapter mBluetoothAdapter){
        Log.d(TAG,"btnDiscover: Looking for unpaired deviced.");

        if(mBluetoothAdapter.isDiscovering()){
            mBluetoothAdapter.cancelDiscovery();
            Log.d(TAG, "btnDiscover: Canceling discovery.");

            checkBTPermission();

            mBluetoothAdapter.startDiscovery();
            IntentFilter discoverDevicesIntent = new IntentFilter(BluetoothDevice.ACTION_FOUND);
            registerReceiver(mBroadcastReceiver,discoverDevicesIntent);
        }
        if(!mBluetoothAdapter.isDiscovering()){
            checkBTPermission();

            mBluetoothAdapter.startDiscovery();
            Log.d(TAG, "Start Discovery");
            IntentFilter discoverDevicesIntent = new IntentFilter(BluetoothDevice.ACTION_FOUND);
            registerReceiver(mBroadcastReceiver,discoverDevicesIntent);
        }

    }

    @RequiresApi(api = Build.VERSION_CODES.M)
    public void checkBTPermission() {
        if (Build.VERSION.SDK_INT > Build.VERSION_CODES.LOLLIPOP) {
            int permissionCheck = this.checkSelfPermission("<Manifest.permission.ACCESS_FINE_LOCATION");
            permissionCheck += this.checkSelfPermission("Manifest.permission.ACCESS_COARSE_LOCATION");
            if (permissionCheck != 0) {
                this.requestPermissions(new String[]{Manifest.permission.ACCESS_FINE_LOCATION, Manifest.permission.ACCESS_COARSE_LOCATION}, 1001);
            } else {
                Log.d(TAG, "checkBTPermissions: No need to check permissions. SDK version < LOLLIPOP.");
            }

        }
    }

    @Override
    public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
        //first cancel discovery because its very memory intensive.
        mBluetoothAdapter.cancelDiscovery();

            Log.d(TAG, "onItemClick: You Clicked on a device.");
            String deviceName = mBTDevices.get(i).getName();
            String deviceAddress = mBTDevices.get(i).getAddress();

            Log.d(TAG, "onItemClick: deviceName = " + deviceName);
            Log.d(TAG, "onItemClick: deviceAddress = " + deviceAddress);

            //create the bond.
            //NOTE: Requires API 17+? I think this is JellyBean
            if(Build.VERSION.SDK_INT > Build.VERSION_CODES.JELLY_BEAN_MR2){
                Log.d(TAG, "Trying to pair with " + deviceName);
                mBTDevices.get(i).createBond();

            }
        }
}
