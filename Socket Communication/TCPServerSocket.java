import java.net.*;
import java.util.*;
import java.io.*;

public class TCPServerSocket {
    public static void main(String[] args) throws Exception{
        try{
            ServerSocket server = new ServerSocket(8888);
            Socket client = server.accept();
            DataInputStream input = new DataInputStream(client.getInputStream());
            DataOutputStream output = new DataOutputStream(client.getOutputStream());
            BufferedReader userin = new BufferedReader(new InputStreamReader(System.in));
            String clientMsg = "", serverRsp = "";
            clientMsg = input.readUTF();
            System.out.println("Message received from Client: "+clientMsg);
            System.out.print("Enter message to send to client: ");
            serverRsp = userin.readLine();
            System.out.println("Sending message to client...");
            output.writeUTF(serverRsp);
            output.flush();
            server.close();
            client.close();
            input.close();
            output.close();
            }
        catch(Exception e){
            System.out.println("An exception occured!");
            System.exit(1);
        }
    }
}
