// left and right motors had different speeds so they were made equal

int l_ir=13; //left_ir
int r_ir=8;  //right_ir
int c_ir=12; //centre_ir
int l_wheel1 = 5, l_wheel2 = 6;
int r_wheel1 = 10, r_wheel2 = 9;
int speed_l = 71;
int speed_r = 79;

void setup()
{
  pinMode(l_ir,INPUT);
  pinMode(r_ir,INPUT);
  pinMode(c_ir,INPUT);
  pinMode(l_wheel1,OUTPUT);
  pinMode(r_wheel1,OUTPUT);
  pinMode(l_wheel2,OUTPUT);
  pinMode(r_wheel2,OUTPUT);
}

void loop()
{
  int al = digitalRead(l_ir);
  int ar = digitalRead(r_ir);
  int ac = digitalRead(c_ir);
  
// Left
  if ((al==1 && ac==0 && ar==0)||(al==1 && ac==1 && ar==0))
  {
    analogWrite(r_wheel1,speed_r);
    analogWrite(r_wheel2,0);
    analogWrite(l_wheel1,0);
    analogWrite(l_wheel2,0);
  }
  
// Right
  if ((al==0 && ac==0 && ar==1) || (al==0 && ac==1 && ar==1))
  {
    analogWrite(l_wheel1,70);
    analogWrite(l_wheel2,0);
    analogWrite(r_wheel1,0);
    analogWrite(r_wheel2,15);
  }
//When it meets a end line
  if(al==0 && ac==0 && ar==0)
  {
    //Left and right moves in clockwise and anticlockwise direction
    analogWrite(l_wheel1,0);
    analogWrite(l_wheel2,speed_l);
    analogWrite(r_wheel1,speed_r);      
    analogWrite(r_wheel2,0);    
  }
  
//When it meets a t-junction 
  if(al==1 && ac==1 && ar==1)
  {
    //Left and right tyres move in clockwise and anticlockwise direction
    analogWrite(l_wheel1,0);
    analogWrite(l_wheel2,0);
    //turns left
    analogWrite(r_wheel1,speed_r);      
    analogWrite(r_wheel2,0); 
  }

//Forward
  if(al==0 && ac==1 && ar==0)
  {
    analogWrite(l_wheel1,speed_l);
    analogWrite(l_wheel2,0);
    analogWrite(r_wheel1,speed_r);
    analogWrite(r_wheel2,0);  
  }  
}
