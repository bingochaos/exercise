package socket;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server {
	private List<ClientThread> clients = new ArrayList<ClientThread>();
	private ServerSocket serverSocket = null;
	private boolean started=false;
	public Server(){
		try {
			serverSocket =  new ServerSocket(8088);
			started = true;
		} catch (IOException e) {
			System.out.println("newSocket error\n");
			e.printStackTrace();
		}
	}
	
	public void start(){
		Socket socket;
		try {
			socket = serverSocket.accept();
			System.out.println("join\n");
			if(socket!=null){
				ClientThread client = new ClientThread(socket,true);
				clients.add(client);
				new Thread(client).start();
			}
		} catch (IOException e) {
			System.out.println("accept error\n");
			e.printStackTrace();
		}
		
	
	}
	public class ClientThread implements Runnable{
		private boolean connected = false;
		private Socket socket = null;
		private DataInputStream dataInputStream = null;
		private DataOutputStream dataOutputStream = null;
		
		public ClientThread(Socket socket,boolean connected) {
			this.socket = socket;
			this.connected  = connected;
			
		}

		@Override
		public void run() {
			InetAddress inetAddress = null;
			int port = 8088;
			try {
			if(connected){
				dataInputStream = new DataInputStream(socket.getInputStream());
				dataOutputStream = new DataOutputStream(socket.getOutputStream());
				inetAddress = socket.getInetAddress();
				port = socket.getPort();
			}
			while (connected) {
				String bufString = dataInputStream.readUTF();
				if(bufString.equals("exit")){
					clients.remove(this);
					connected = false;
				}
				System.out.println("From:"+inetAddress.toString()+":"+port+": "+bufString);
				for(int i = 0;i<clients.size();i++){
					clients.get(i).dataOutputStream.writeUTF("From:"+inetAddress.toString()+":"+port+": "+bufString);
				}
				
			}
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			
			
		}
		
	}
	public static void main(String args[]){
		Server server = new Server();
		while (server.started) {
			server.start();
		}
		
	}
}
