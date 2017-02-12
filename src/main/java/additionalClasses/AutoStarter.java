package additionalClasses;

import java.io.IOException;

import javax.swing.JOptionPane;

import com.izforge.izpack.panels.process.AbstractUIProcessHandler;


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
        
        boolean autoStart = (args[0].toLowerCase().equals("on$"));
        
        String pathToProgram = args[1];
        
        boolean linux = (args[2].equals("1"));
        
        if (autoStart) {
           if (linux) {
               startOnLinux(pathToProgram);
           } else {
               startOnWindows(pathToProgram);
           }
        }
        
    }

    private void startOnWindows(String pathToJar) {
        String callArgument = "cmd.exe /c java -jar " + pathToJar;
        
        try {
            Runtime.getRuntime().exec(callArgument);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    private void startOnLinux(String pathToJar) {

        pathToJar.replaceAll("\"", "");
        pathToJar = pathToJar.replace("\\", "/");
        
        
        JOptionPane.showMessageDialog(null, pathToJar);
        
        try {
            ProcessBuilder builder = new ProcessBuilder("/bin/java", "-jar", pathToJar);
            builder.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
