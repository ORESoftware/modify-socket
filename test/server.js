const addon = require('../build/Release/run.node');

const net = require('net');
const util = require('util');

const s = net.createServer(s => {

  try{
    const fd = s._handle.fd;
    console.log('the fd:', fd);
    const val = addon.run(fd);
    console.log('the val:', val);
  }
  catch(err){
    console.error(err);
  }

});

s.listen(3030);

setTimeout(function(){
  console.log(util.inspect(s));
}, 100);



