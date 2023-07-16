class ParkingSystem {

  public:
    const int m_max_big;
    const int m_max_medium;
    const int m_max_small;
    int m_num_big = 0;
    int m_num_medium = 0;
    int m_num_small = 0;

  public:
    ParkingSystem(int big, int medium, int small) : m_max_big{ big }, m_max_medium{ medium }, m_max_small{ small }
    {
    }

    bool addCar(int carType)
    {
        switch (carType) {
        case 1:
            if (m_num_big < m_max_big) {
                ++m_num_big;
                return true;
            }
            else {
                return false;
            }

        case 2:
            if (m_num_medium < m_max_medium) {
                ++m_num_medium;
                return true;
            }
            else {
                return false;
            }
            break;

        case 3:
            if (m_num_small < m_max_small) {
                ++m_num_small;
                return true;
            }
            else {
                return false;
            }
            break;

        default:
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */