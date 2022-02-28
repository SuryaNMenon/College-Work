import java.io.*;
import java.util.*;
import java.net.*;

public class TCPClientSocket {
    public static void main(String[] args) throws Exception{
        try{
            Socket client = new Socket("127.0.0.1", 8888);
            DataInputStream input = new DataInputStream(client.getInputStream());
            DataOutputStream output = new DataOutputStream(client.getOutputStream());
            BufferedReader userin = new BufferedReader(new InputStreamReader(System.in));
            String clientMsg = "", serverRsp = "";
            System.out.print("Enter message to send to server: ");
            clientMsg = userin.readLine();
            output.writeUTF(clientMsg);
            output.flush();
            serverRsp = input.readUTF();
            System.out.print("Message received from server: "+serverRsp);
            client.close();
            input.close();
            output.close();
            userin.close();
        }
        catch(Exception e){
            System.out.println("Exception occured");
            System.exit(1);
        }
    }
}
