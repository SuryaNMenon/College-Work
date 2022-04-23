import java.io.*;
import java.net.*;

public class sandbox1{
    static ServerSocket server;
    static DataInputStream dis;
    static DataOutputStream dos;
    public static void main(String[] args) throws SocketException {
        try{
            ServerSocket server = new ServerSocket(8011);
            System.out.println("Waiting for connection");
            Socket client = server.accept();
            DataInputStream dis = new DataInputStream(client.getInputStream());
            DataOutputStream dos = new DataOutputStream(client.getOutputStream());

            int data[] = {10,20,30,40,50,60,70};
            System.out.println("Number of frames sent is: "+ data.length);
            dos.write(data.length);
            dos.flush();

            for(int i = 0; i<data.length; i++){
                System.out.println("Transmitting frame: "+ data[i]);
                dos.write(data[i]);
                dos.flush();
            }

            int m = dis.read();
            dos.write(data[m]);
            dos.flush();
            System.out.println("Transfer complete");
        }catch(IOException e){e.printStackTrace();}
        finally{try{
            dis.close();
            dos.close();
        }catch(IOException e){e.printStackTrace();}}
    }
}