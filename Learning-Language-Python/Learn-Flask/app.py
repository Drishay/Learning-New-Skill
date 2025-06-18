from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")  #end points just like og websites
def hello_world():
    return render_template("index.html")
    # return "Hello, world" 

@app.route("/products")
def product():
    return "this is product page"
 
if __name__ == "__main__":
    app.run(debug=True, port = 8000)