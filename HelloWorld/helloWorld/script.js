// create a network
var i = 0;
var curr_data;
var container = document.getElementById('mynetwork');
var container2 = document.getElementById('mynetwork2');
var genNew = document.getElementById('generate-graph');
var solve = document.getElementById('solve');
var temptext = document.getElementById('temptext');

// var cpphello = require('./cpphello');

// cpphello.foo(); // hello world

// initialise graph options
var options = {
    edges: {
        arrows: {
            to: true
        },
        labelHighlightBold: true,
        font: {
            size: 20
        }
    },
    nodes: {
        font: '12px arial red',
        scaling: {
            label: true
        },
        shape: 'icon',
        icon: {
            face: 'FontAwesome',
            code: '\uf183',
            size: 50, //50,
            color: '#991133',
        }
    }
};
// initialize your network!
var network = new vis.Network(container);
network.setOptions(options);
var network2 = new vis.Network(container2);
network2.setOptions(options);
nodes = [];
edges = [];

function search(nameKey, myArray) {
    for (var i = 0; i < myArray.length; i++) {
        if (myArray[i].label === nameKey) {
            return myArray[i].id;
        }
    }
}

function addfriend() {
    var name = document.getElementById("input1");
    console.log(name.value);
    nodes.push({ id: i + 1, label: name.value });
    i = i + 1;
}

function addRelationship() {
    var name1 = document.getElementById("name1");
    var name2 = document.getElementById("name2");
    var amount = document.getElementById("amount");
    console.log(name1.value);
    console.log(name2.value);
    console.log(amount.value);
    edges.push({ from: search(name1.value, nodes), to: search(name2.value, nodes), label: amount.value });
}

function createData() {
    nodes = new vis.DataSet(nodes);
    data = {
        nodes: nodes,
        edges: edges
    };
    curr_data = data;
    network.setData(curr_data);
    temptext.style.display = "inline";
    container2.style.display = "none";
}

solve.onclick = function() {
    temptext.style.display = "none";
    container2.style.display = "inline";
    solvedData = solveData();
    network2.setData(solveData());
};

function solveData() {
    data = curr_data;
    sz = data['nodes'].length;
    vals = Array(sz).fill(0);
    for (i = 0; i < data['edges'].length; i++) {
        edge = data['edges'][i];
        console.log(edge);
        vals[edge['to'] - 1] += parseInt(edge['label']);
        vals[edge['from'] - 1] -= parseInt(edge['label']);
    }
    for (i = 0; i < sz; i++)
        console.log(vals[i]);
    console.log('\n');

    new_edges = [];
    for (i = 0; i < sz; i++) {
        if (vals[i] > 0) {
            for (j = 0; j < sz && vals[i] > 0; j++) {
                if (vals[j] < 0) {
                    if (vals[j] + vals[i] >= 0) {
                        new_edges.push({ from: j + 1, to: i + 1, label: String(Math.abs(vals[j])) });
                        vals[i] += vals[j];
                        vals[j] = 0;
                    } else {
                        new_edges.push({ from: j + 1, to: i + 1, label: String(vals[i]) });
                        vals[j] += vals[i];
                        vals[i] = 0;
                    }
                }
            }
        }
    }

    data = {
        nodes: data['nodes'],
        edges: new_edges
    };
    return data;
}