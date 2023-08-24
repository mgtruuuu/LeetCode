class TrafficLight 
{
    public:
    mutex m;
    int light=1; //which light is currently on
    TrafficLight() 
    {}

    void carArrived(int carId,int roadId,int direction,function<void()> turnGreen,function<void()> crossCar) 
    {
        m.lock();
        if(light!=roadId) //if the light is not green on the current road, we should switch the light
		{
			turnGreen();
			light=roadId;
		}
        crossCar();
        m.unlock();
    }
};