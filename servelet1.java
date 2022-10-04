

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class Servlet1
 */
@WebServlet("/Servlet1")
public class Servlet1 extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Servlet1() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		PrintWriter out=response.getWriter();
		String Id=request.getParameter("id");
		out.print("<h1>Display the record</h1>");
		out.print("<table border='1'><tr><th>Actor Id</th><th>First_Name</th><th>Last_Name</th><th>Last_update</th></tr>");
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/sakila","root","root");
			Statement stmt=con.createStatement();
			ResultSet rs=stmt.executeQuery("select *from mytable where cust_number="+Id+""); 
			while(rs.next()) {
				out.print("<tr><td>");
				out.println(rs.getInt(1));
				out.print("</td>");
				out.print("<td>");
				out.print(rs.getString(2));
				out.print("</td>");
				out.print("<td>");
				out.print(rs.getString(3));
				out.print("</td>");
				out.print("<td>");
				out.print(rs.getString(4));
				out.print("</td>");
			}
		}catch(Exception p) {
			System.out.println(p);
		}
		out.print("</table>");
//		update Queery====>>>>>"INSERT INTO mytable (name_customer, cust_number, invoice_id, total_open_amount, due_in_date, notes) values (?, ?, ?, ?, ?, ?)";
//delete querry==========>>>>>>>>>>"DELETE FROM mytable WHERE FIELD1 = ?";
//		Edit querry============>>> "UPDATE mytable SET total_open_amount = ?, notes = ? WHERE FIELD1 = ?";
	
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doGet(request, response);
	}

}
