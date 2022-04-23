import java.io.*;
import java.net.*;
import java.util.*;

public class TCPEchoServer{
    private static ServerSocket server;
    private static final int PORT = 1234;
    public static void main(String[] args) {
        System.out.println("Establishing connection...");
        try{
            System.out.println("Connection Established!");
            server = new ServerSocket(PORT);
        }
        catch(IOException e){
            System.out.println("Unable to open Port");
            System.exit(1);
        }
        clientInteract();
    }
    private static void clientInteract() {
        Socket link = null;
        try{
            link = server.accept();
            Scanner input = new Scanner(link.getInputStream());
            PrintWriter output = new PrintWriter(link.getOutputStream(), true);
            String message = input.nextLine();
            int numMsg = 0;
            while(!message.equals("CLOSE")){
                System.out.println("Message received!");
                numMsg++;
                System.out.println("Echoing message number "+numMsg);
                output.println("Message "+numMsg+": "+message);
                message = input.nextLine();
            }
        }
        catch(IOException e){e.printStackTrace();}
        finally{
            try{
                System.out.println("Terminating open connection");
                link.close();
            }
            catch(IOException e){
                System.out.println("Unable to close connection.");
                System.exit(1);
            }
        }
    }
}

