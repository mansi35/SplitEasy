#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
void set_content_type(string content_type) {
	cout << "Content-type: " << content_type << "\r\n\r\n";
}
void set_page_title(string title) {
	cout << "<title>" << title << "</title>\n";
}
void h1_text(string text) {
	cout << text << "\n";
}
int main() {
	set_content_type("text/html");
	// Output HTML boilerplate
	cout << "<!doctype html>\n";
	cout << "<html lang=\"en\">\n";
	cout << "<head>\n";
	set_page_title("Hello, World!");
	cout << "<link rel = \"stylesheet\" href = \"https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css\" integrity = \"sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm\" crossorigin = \"anonymous\">\n";
	cout << "<script src = \"https://kit.fontawesome.com/5548f5ed00.js\" crossorigin = \"anonymous\"></script>\n";
	cout <<	"<script type = \"text/javascript\" src = \"https://unpkg.com/vis-network/standalone/umd/vis-network.min.js\"></script>\n";
	cout << "<script defer src=\"script.js\"></script>\n";
	cout << "<link rel=\"stylesheet\" href=\"StyleSheet.css\"\n";
	cout << "</head>\n";
	cout << "<body>\n";
	cout << "<div class=\"container\">\n";
	cout << "<div class=\"content\">\n";
	cout << "<ul id=\"list\">\n";
	cout << "</ul>\n";
	cout << "</div>\n";
	cout << "<div class=\"add-to-do\">\n";
	cout << "<button><i class=\"fa fa-plus-circle\" onclick=\"addfriend()\"></i></button>\n";
	cout << "<input type=\"text\" id=\"input1\" placeholder=\"Add a to-do\">\n";
	cout << "</div>\n";
	cout << "</div>\n";
	/* for (int i = 0; i < friends; i++) {
		if (i == 0) {
			cout << "<script src=\"script.js\">";
			cout << "addfriend(\"shrishti\"," + to_string(i) + ");";
			cout << "</script>\n";
		}
		else if (i == 1) {
			cout << "<script src=\"script.js\">";
			cout << "addfriend(\"mansi\"," + to_string(i) + ");";
			cout << "</script>\n";
		}
		else {
			cout << "<script src=\"script.js\">";
			cout << "addfriend(\"riya\"," + to_string(i) + ");";
			cout << "</script>\n";
		}
	} */
	cout << "<div>";
	cout << "<input type=\"text\" id=\"name1\" placeholder=\"friend 1\">\n";
	cout << "<input type=\"text\" id=\"name2\" placeholder=\"friend 2\">\n";
	cout << "<input type=\"text\" id=\"amount\" placeholder=\"amount\">\n";
	cout << "<button onclick=\"addRelationship()\"><input type=\"submit\" value=\"submit\"></button>";
	cout << "</div>";
	/* while (no--) {
		if (no == 3) {
			x = "shrishti";
			y = "mansi";
			amount = 20;
			cout << "<script src=\"script.js\">";
			cout << "addRelationship(\"" + x + "\", \"" + y + "\", " + to_string(amount) + ");";
			cout << "</script>\n";
		}
		else if (no == 2) {
			x = "riya";
			y = "shrishti";
			amount = 10;
			cout << "<script src=\"script.js\">";
			cout << "addRelationship(\"" + x + "\", \"" + y + "\", " + to_string(amount) + ");";
			cout << "</script>\n";
		}
		else {
			x = "mansi";
			y = "riya";
			amount = 12;
			cout << "<script src=\"script.js\">";
			cout << "addRelationship(\"" + x + "\", \"" + y + "\", " + to_string(amount) + ");";
			cout << "</script>\n";
		}
	} */
	cout << "<div>";
	cout << "<button onclick=\"createData()\">Submit</button>";
	cout << "</div>";
	cout << "<nav class=\"navbar navbar-light\" style=\"font-size: 25px; font-family: sans-serif; background-color: whitesmoke;\">";

	cout << "<img src=\"https://codingblocks.com/assets/images/cb/cblogo.png\" width=\"124\" height=\"45\" class=\"d-inline-block align-top\"> Friend Cash Flow Solver Student Project";

	cout << "</nav>";
	cout << "<div id=\"container\">";
	cout << "<div id=\"mynetwork\"></div>";
	cout << "<div id=\"container2\">";
	cout << "<span id=\"temptext\" style=\"width: 100%; text-align: center; font-size: x-large\">";
	cout << "Click on solve to get Solution !!";
	cout << "</span>";
	cout << "<div id = \"mynetwork2\" style=\"display: none\"></div>";
	cout << "</div>";
	cout << "</div>";

	cout << "<div>";
	cout << "<br>";
	cout << "<button type=\"button\" class=\"btn btn-danger\" id=\"generate-graph\">Get New Problem</button>";
	cout << "<br>";
	cout << "<button type=\"button\" class=\"btn btn-success\" id=\"solve\">Solve</button>";
	cout << "</div>";
	cout << "</body>\n";
	cout << "</html>";
	return 0;
}