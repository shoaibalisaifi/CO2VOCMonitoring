var amq = require('amqplib');


        async function logs(message){
            var rabbitmqqueue = 'co2voc';
            const connection = await amq.connect('amqp://guest:guest@192.168.1.163:5672');
            const channel = await connection.createChannel();
            await channel.assertQueue(rabbitmqqueue, {durable: false});
            channel.sendToQueue(rabbitmqqueue, Buffer.from(message));
         }

            

        exports.handler = function(context, _occurence) {
            var _occurence = JSON.parse(JSON.stringify(_occurence));
            var _info = String.fromCharCode(..._occurence.body.data);

            context.callback("response "+_info);
            logs("details "+_info);
            
            }
