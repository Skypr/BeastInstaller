package additionalClasses;

import java.awt.Dimension;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;

import com.izforge.izpack.panels.packs.PacksPanel;
import com.izforge.izpack.panels.process.AbstractUIProcessHandler;
import com.izforge.izpack.util.IoHelper;

public class AutoStarter {

    /**
     * As per <a href=
     * "http://docs.codehaus.org/display/IZPACK/Executing+a+Java+Class+with+ProcessPanel">
     * Executing a Java Class with ProcessPanel</a> of the izPack documentation,
     * the external Java class must have a run() method with some parameters.
     * <br>
     * <br>
     * <b>Note:</b> This is not (NOT!) the run() method from the
     * java.lang.Runnable interface. Nor is this codified as an interface in the
     * IzPack javadoc.
     * 
     * @param handler
     *            {@link AbstractUIProcessHandler} used to emit errors.
     * @param args
     *            String array with all of the specific arguments.
     */
    public void run(AbstractUIProcessHandler handler, String[] args) {

        boolean autoStart = (args[0].equals("1"));
        
        String pathToProgram = args[1];
        
        boolean linux = (args[2].equals("1"));
        
       
    }

}
