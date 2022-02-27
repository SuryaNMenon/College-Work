import java.lang.*;
import java.util.*;
import java.net.*;
import java.io.*;
import java.text.*;

public class selectiveRepeatClient{
    static Socket connection;
    public static void main(String[] args) throws SocketException{
        try{
            int v[] = new int[8];
            int n = 0;
            Random random = new Random();
            int value;

            InetAddress addr = InetAddress.getByName("Localhost");
            System.out.println("Connecting to: "+addr);
            connection = new Socket(addr, 8011);
            DataInputStream dis = new DataInputStream(connection.getInputStream());
            DataOutputStream dos = new DataOutputStream(connection.getOutputStream());
            int count = dis.read();
            System.out.println("Number of packets sent: " + count);

            for(int i=0;i<count;i++){
                v[i] = dis.read();
                System.out.println("Data being transmitted: " +v[i]);
            }

            value = random.nextInt(count);
            v[value] = -1;
            for(int i = 0; i<count; i++){
                System.out.println("Packet received: "+v[i]);
            }
            for(int i=0;i<v.length;i++)
                if(v[i] == -1){
                    System.out.println("Requesting retransmission for packet number "+(i+1));
                    n = i;
                    dos.write(n);
                    dos.flush();
                }
                System.out.println();
                v[n] = dis.read();
                System.out.println("Retransmitted packet is: "+v[n]);
            System.out.println("Data Transfer Complete - Terminating!");
        }catch(Exception e){System.out.println(e);}
    }
}