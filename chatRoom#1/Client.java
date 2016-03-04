package socket;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {
	private boolean connected = false;
	private DataOutputStream dataOutputStream = null;
	private DataInputStream dataInputStream = null;
	public Client() {
		// TODO Auto-generated constructor stub
	}
	public static void main(String args[]){
		Client client = new Client();
		client.Connect();
		client.Listen();
	}
	private void Connect() {
		try {
			Socket socket = new Socket(InetAddress.getByName("127.0.0.1"),8088);
			connected = true;
			
			dataOutputStream = new DataOutputStream(socket.getOutputStream());
			dataInputStream = new DataInputStream(socket.getInputStream());
			dataOutputStream.writeUTF("hello");
		} catch (UnknownHostException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	private void Listen() {
		new Thread(new ListenThread()).start();
	}
	public class ListenThread implements Runnable {

		@Override
		public void run() {
			while(connected){
				String backString;
				try {
					
					backString = dataInputStream.readUTF();
					System.out.println(backString);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
			
		}
		
	}
}
