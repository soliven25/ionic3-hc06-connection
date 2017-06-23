import { Component } from '@angular/core';
import { NavController } from 'ionic-angular';
import { BluetoothSerial } from '@ionic-native/bluetooth-serial';

@Component({
  selector: 'page-home',
  templateUrl: 'home.html'
})
export class HomePage {

  public working:string;
  public var2: string ;
  public lists = [];

  constructor(public navCtrl: NavController, private bluetoothSerial: BluetoothSerial) {
   
    bluetoothSerial.isEnabled()
        .then(( succes ) => { 
            alert('Bluetooth enabled'); 
            bluetoothSerial.list()
              .then(function(result){
                alert('Getting List Success');

                var hc06 = result.find(obj => {
                  if (obj.name == 'HC-06')
                   return obj;
                });
                alert(hc06.address);
                bluetoothSerial.connect(hc06.address)
                  .subscribe(data => {
                    alert('Connection Success');
                  }, error => {
                    alert('Connection Failed');
                  });
              }, function(failure){
                  alert('Getting List Failed');
                  alert(failure);
              });                                      
        },( err ) => {
            bluetoothSerial.enable()
                .then(( succes ) => { alert('enabling bluetooth worked.' ); 
                    },( err ) => { alert('cant enable bluetooth.');
                });
        });

    alert('HC-06 Connection Start!');
  }

  ledOn() {
    this.bluetoothSerial.write('ON');
  }

  ledOff() {
    this.bluetoothSerial.write('OFF');
  }
}
