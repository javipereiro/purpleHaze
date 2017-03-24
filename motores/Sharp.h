class Sharp
{
public:
    int distance;
	int pin=-1;
	void pinAssign(int a)
	{
		pin=a;
	}
    int pinRead(int a)
    {
        distance=analogRead(a);
		return distance;
    }
	int pinRead(void){
		if(pin!=-1){
		distance = analogRead(pin);
		return distance;
		}
		else return -1;
	}
};
