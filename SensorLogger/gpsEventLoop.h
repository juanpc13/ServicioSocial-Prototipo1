void adjustTime( NeoGPS::time_t & dt ) {
  dt = dt + (utc) * (60 * 60) ;
}
void gpsEventLoop() {
  if (gps.available( gpsPort )) {
    gps_fix fix = gps.read();
    if (fix.valid.date && fix.valid.time && fix.valid.location && fix.valid.altitude) {
      adjustTime(fix.dateTime);
      ReadAllData();
      saveData(fix);
    }
  }
}
