import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

public class selectiveRepeatServer{
   static ServerSocket server;
   static DataInputStream dis;
   static DataOutputStream dos;
   public static void main(String[] args) throws SocketException {
        try{
            int a[] = {30, 40, 50, 60, 70, 80, 90, 20};
            ServerSocket server = new ServerSocket(8011);
            System.out.println("Waiting for connection...");
            Socket client = server.accept();
            DataInputStream dis = new DataInputStream(client.getInputStream());
            DataOutputStream dos = new DataOutputStream(client.getOutputStream());
            System.out.println("Number of packets sent is: "+ a.length);
            dos.write(a.length);
            dos.flush();

            for(int i = 0; i<a.length; i++){
                dos.write(a[i]);
                dos.flush();
            }

            int k = dis.read();
            dos.write(a[k]);
            dos.flush();
        }catch(IOException e){System.out.println(e);}
        
        finally{
            try{
                dos.close();
                dis.close();
            }
            catch(IOException e){
                e.printStackTrace();
            }
        }
   }
}