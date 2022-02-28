import java.util.*;
import java.net.*;
import java.io.*;

public class TCPEchoClient{
    static InetAddress host;
    static final int PORT = 1234;
    public static void main(String[] args) {
        try{
            host = InetAddress.getByName("Localhost");
        }
        catch(UnknownHostException e){
            e.printStackTrace();
        }
        serverInteract();
    }
    private static void serverInteract() {
        Socket link = null;
        try{
            link = new Socket(host, PORT);
            Scanner input = new Scanner(link.getInputStream());
            PrintWriter output = new PrintWriter(link.getOutputStream(), true);
            Scanner userInputer = new Scanner(System.in);
            String message, response;
            do{
                System.out.println("Enter message: ");
                message = userInputer.nextLine();
                output.println(message);
                response = input.nextLine();
                System.out.println("SERVER> Message: "+response);
            }while(!message.equals("CLOSE"));
        }
        catch(IOException e){
            e.printStackTrace();
        }
        finally{
            try{
                link.close();
            }
            catch(IOException e){
                e.printStackTrace();
            }
        }
    }
}