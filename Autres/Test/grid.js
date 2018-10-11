class	Perso
{
	constructor(name, nb){
		this.name = name;
		if (nb == 1){
			this.x = 1;
			this.y = 1;
		}
		else{
			this.x = 8;
			this.y = 8;
		}
		this.HP = 10;
		this.PM = 4;
	}

	life(){
		return (this.HP);
	}

	move(){
		return (this.move);
	}

	loseLife(n){
		this.HP = this.HP - n;
		return (this.HP);
	}

	losePM(n){
		this.PM = this.PM - n;
		return (this.PM);
	}
	
	change_pos(x, y){
		this.x = x;
		this.y = y;
	}

	give_pos(){
		return (this.x + ";" + this.y);
	}

}

function	move_to_case(x, y){
	console.log(x);
	console.log(y);
	p1.change_pos(x, y);
	ft_display_grid();
}

function	ft_display_grid()
{
	var		x;
	var		y;
	
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			var		td = document.getElementById(x + ";" + y);
			if (p1.give_pos() == x + ";" + y){
				td.setAttribute("style", "background-color : red; border-radius : 5px");
			}
			else if (p2.give_pos() == x + ";" + y){
				td.setAttribute("style", "background-color : green; border-radius : 5px");
			}
			else{
				td.setAttribute("onclick", "move_to_case(" + x + "," + y + ")");
			}
			td.setAttribute('id', x + ";" + y);
			y++;
		}
		x++;
	}
}

function	ft_create_grid()
{
	var		x;
	var		y;
	var		table;
	
	table = document.getElementById("grid");
	x = 0;
	while (x < 10)
	{
		var		tr = document.createElement("tr");
		y = 0;
		while (y < 10)
		{
			var		td = document.createElement("td");
			if (ta[x + ";" + y] == 1)
				td.setAttribute("style", "background-color : grey; border-radius : 5px");
			else if (p1.give_pos() == x + ";" + y){
				td.setAttribute("style", "background-color : red; border-radius : 5px");
				td.appendChild(document.createTextNode(p1.name));
			}
			else if (p2.give_pos() == x + ";" + y){
				td.setAttribute("style", "background-color : green; border-radius : 5px");
				td.appendChild(document.createTextNode(p2.name));
			}
			else{
				td.setAttribute("onclick", "move_to_case(" + x + "," + y + ")");
				td.appendChild(document.createTextNode(x + ";" + y));
			}
			td.setAttribute('id', x + ";" + y);
			tr.appendChild(td);
			y++;
		}
		x++;
		table.appendChild(tr);
	}
}

var ta = [];

for (var i = 0; i++; i < 10)
	for (var j = 0; j++; j < 10)
		ta[i + ";" + j] = 0;

ta["1;4"] = 1;

ta["2;2"] = 1;
ta["3;2"] = 1;
ta["3;3"] = 1;

ta["3;5"] = 1;
ta["3;6"] = 1;
ta["3;7"] = 1;
ta["3;7"] = 1;

ta["5;1"] = 1;
ta["5;2"] = 1;
ta["6;2"] = 1;
ta["7;2"] = 1;
ta["8;2"] = 1;

ta["5;5"] = 1;
ta["6;5"] = 1;
ta["6;6"] = 1;

ta["5;8"] = 1;

ta["7;8"] = 1;

ta["8;4"] = 1;

var		p1 = new Perso("Michel", 1);
var		p2 = new Perso("Jacky", 2);


ft_create_grid();

