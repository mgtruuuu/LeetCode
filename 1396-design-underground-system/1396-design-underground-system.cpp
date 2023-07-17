class UndergroundSystem {

  private:
    std::unordered_map<int, std::pair<std::string, int>> id_2_start_info; // id, startStation, startTime
    std::unordered_map<std::string, std::pair<int, int>> station_2_avg;   // station, sum, count

  public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        id_2_start_info[id] = { stationName, t };
    }

    void checkOut(int id, string stationName, int t)
    {
        const auto station_combined = id_2_start_info[id].first + "_" + stationName;

        if (station_2_avg.find(station_combined) == station_2_avg.end()) {
            station_2_avg[station_combined] = { t - id_2_start_info[id].second, 1 };
        }
        else {
            station_2_avg[station_combined].first += (t - id_2_start_info[id].second);
            ++station_2_avg[station_combined].second;
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        const auto& avg = station_2_avg[(startStation + "_" + endStation)];

        return static_cast<double>(avg.first) / avg.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */