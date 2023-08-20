package com.macpgames.macpanimaldeterrent;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;

import com.macpgames.macpanimaldeterrent.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'macpanimaldeterrent' library on application startup.
    static {
        System.loadLibrary("macpanimaldeterrent");
    }

    private native void switchSoundOn();
    private native void switchSoundOff();

    private native void startEngine(float frequency);
    private native void stopEngine();

    private ActivityMainBinding binding;

    private AnimalFrequencies _animalFrequencies;

    private float _frequency;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        _animalFrequencies = new AnimalFrequencies();
        _frequency = _animalFrequencies.test;
    }

    public void buttonStart_onClick(View view)
    {
        startEngine(_frequency);
        switchSoundOn();
        binding.buttonStart.setEnabled(false);
        binding.buttonStart.setText(R.string.status_playing);
    }

    public void buttonStop_onClick(View view)
    {
        switchSoundOff();
        stopEngine();
        binding.buttonStart.setText(R.string.button_start);
        binding.buttonStart.setEnabled(true);
    }

    public void radioButtonDog_onClick(View view){
        _frequency = _animalFrequencies.dog;
    }
    public void radioButtonCat_onClick(View view){
        _frequency = _animalFrequencies.cat;
    }
    public void radioButtonBear_onClick(View view){
        _frequency = _animalFrequencies.bear;
    }
    public void radioButtonCoyote_onClick(View view){
        _frequency = _animalFrequencies.coyote;
    }
    public void radioButtonWolf_onClick(View view){
        _frequency = _animalFrequencies.wolf;
    }
    public void radioButtonRaccoon_onClick(View view) { _frequency = _animalFrequencies.raccoon; }

    @Override
    public void onDestroy() {
        stopEngine();
        super.onDestroy();
    }
}