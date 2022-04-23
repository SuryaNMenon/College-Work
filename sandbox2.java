import java.lang.*;
import java.util.*;
import java.net.*;
import java.io.*;
import java.text.*;

public class sandbox2{
    static Socket connection;
    public static void main(String[] args) throws SocketException {
        try{
            InetAddress adr = InetAddress.getByName("Localhost");
            Socket connection = new Socket(adr, 8011);
            DataInputStream dis = new DataInputStream(connection.getInputStream());
            DataOutputStream dos = new DataOutputStream(connection.getOutputStream());

            int data[] = new int[dis.read()];
            System.out.println("Number of frames sent is: " +  data.length);

            for(int i = 0; i<data.length; i++){
                data[i] = dis.read();
                System.out.println("Data being transmitted: "+ data[i]);
            }

            Random random = new Random();
            int n = random.nextInt(data.length);
            data[n] = -1;

            for(int i = 0; i<data.length;  i++){
                System.out.println("Data received: "+data[i]);
            }
            int pos;
            for(int i =  0; i<data.length; i++){
                if(data[i] == -1){
                    System.out.println("Request retrasmit frame "+ (i+1));
                    pos = i;
                    dos.write(pos);
                    dos.flush();
                    data[pos] = dis.read();
                    System.out.println("Retransmitted frame: "+ data[pos]);
                }
            }

            System.out.println("Transfer complete");
        }catch(IOException e){e.printStackTrace();}
    }
}