class ParkingSystem {
public:
    int type1;    int type2; int type3;
    ParkingSystem(int big, int medium, int small) {
        type1=big;
        type2=medium;
        type3=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(type1>0){
                  type1--;
                return true;
            }
            else
                return false;
        }
         else if(carType==2){
            if(type2>0){
                  type2--;
                return true;
            }
            else
                return false;
        }
         else if(carType==3){
            if(type3>0){
                type3--;
                return true;
            }
            else
                return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */