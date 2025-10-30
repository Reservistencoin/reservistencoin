package org.reservistencoincore.qt;

import android.os.Bundle;
import android.system.ErrnoException;
import android.system.Os;

import org.qtproject.qt5.android.bindings.QtActivity;

import java.io.File;

public class ReservistenCoinQtActivity extends QtActivity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        final File reservistencoinDir = new File(getFilesDir().getAbsolutePath() + "/.reservistencoin");
        if (!reservistencoinDir.exists()) {
            reservistencoinDir.mkdir();
        }

        super.onCreate(savedInstanceState);
    }
}
