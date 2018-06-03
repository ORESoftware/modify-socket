const addon = require('../build/Release/run.node');



const net = require('net');

const s = net.createServer(s => {

});

const fd = s._handle.fd;

console.log('the fd:',fd);

const val = addon.run(fd);

