from flask import Flask
from flask import request
#from flask_cors import CORS

app = Flask(__name__)
#CORS(app)

@app.route("/")
def mad():
    return """<!DOCTYPE html>

<html lang="en">
<head>
    <meta charset="utf-8">

    <title>Radar</title>
</head>
<body>
    <img src="https://i.imgur.com/BKBGcqf.png" id="map" width="512" height="512" style="position:absolute;">
    <canvas id="radar" width="512" height="512" style="z-index:1000;position:relative;" />
	
	<script>
    const canvas = document.getElementById("radar");
    const ctx = canvas.getContext("2d");

    const map = document.getElementById("map");

    const base_data_path = "/data";

    // radar images are 1024x1024, we are scaling them down to 512x512
    const ratio = 0.5;

    let pos_x = -3230;
    let pos_y = 1713;
    let scale = 5;

    let prev_map_name;

function httpGet(theUrl)
{
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open( "GET", theUrl, false ); // false for synchronous request
    xmlHttp.send( null );
    return xmlHttp.responseText;
}


    function draw_entity(x, y, last_place, r, g, b, a) {


		var mapped_x = ((x - pos_x) / scale) * ratio;
		var mapped_y = ((y - pos_y) / -scale) * ratio;
	
        ctx.beginPath();
        ctx.rect(mapped_x-5, mapped_y-5, 10, 10);
        ctx.fillStyle = `rgb(${ r }, ${ g }, ${ b }, ${ a })`;
        ctx.fill();
	
	ctx.fillStyle = "rgb(51,255,0,255)";
        ctx.font = "12px Arial";
        ctx.fillText(last_place, mapped_x+5, mapped_y+5);

    }

    function clear_canvas() {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
    }

    function normalize(val, min, max) {
        const clamped_val = Math.min(Math.max(val, min), max);

        return (clamped_val - min) / (max - min);
    }



    function normalize(val, min, max) {
        const clamped_val = Math.min(Math.max(val, min), max);

        return (clamped_val - min) / (max - min);
    }

var olddd = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1];

setInterval(function () {

	let data = httpGet("http://45.140.170.123/get");
const now_ms = new Date().getTime();
    data = data.split("A");
	clear_canvas();
	let iii = 0;
	for (let value of data) {
	
	const now_ms = new Date().getTime();
	let datadata;
	datadata = value.split("a");
	
	let health_percentage = normalize(datadata[2], 0, 100);

    let col_red = 255 * health_percentage;
    let col_green = 0;
    let col_blue = 0;


            if ((datadata[3] - olddd[iii]) > 0) {
		olddd[iii]=datadata[3];	
            }else{
		                col_red = 0;
                col_green = 0;
                col_blue = 255;

}
    draw_entity(datadata[0], datadata[1], datadata[2], col_red, col_green, col_blue, 255);
	iii++;
	//draw_entity(datadata[0],datadata[1]);

}
}, 250);    
</script>
	
</body>

"""

@app.route('/data', methods = ['POST'])
def user():
    if request.method == 'POST':
        data = request.form['data']
        f = open("mamd.txt",'w')
        f.write(str(data))
        f.close
        return ""
        
@app.route('/get')
def get():
    f = open("mamd.txt",'r')
    data = f.read()
    f.close
    return data
        
app.run(host='45.140.170.123', port=80)
