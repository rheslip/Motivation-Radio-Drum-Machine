// sample structure built by wav2header based on wav2sketch by Paul Stoffregen

struct sample_t {
  const int16_t * samplearray; // pointer to sample array
  uint32_t samplesize; // size of the sample array
  uint32_t sampleindex; // current sample array index when playing. index at last sample= not playing
  uint8_t MIDINOTE;  // MIDI note on that plays this sample
  uint8_t play_volume; // play volume 0-127
  char sname[20];        // sample name
} sample[] = {

	Bigkickr,	// pointer to sample array
	Bigkickr_SIZE,	// size of the sample array
	Bigkickr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	35,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Bigkickr",	// sample name

	Brushcrashtambr,	// pointer to sample array
	Brushcrashtambr_SIZE,	// size of the sample array
	Brushcrashtambr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	36,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Brushcrashtambr",	// sample name

	Crash1r,	// pointer to sample array
	Crash1r_SIZE,	// size of the sample array
	Crash1r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	37,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Crash1r",	// sample name

	Jingle,	// pointer to sample array
	Jingle_SIZE,	// size of the sample array
	Jingle_SIZE,	//sampleindex. if at end of sample array sound is not playing
	38,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Jingle",	// sample name

	Rider,	// pointer to sample array
	Rider_SIZE,	// size of the sample array
	Rider_SIZE,	//sampleindex. if at end of sample array sound is not playing
	39,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Rider",	// sample name

	Synthrider,	// pointer to sample array
	Synthrider_SIZE,	// size of the sample array
	Synthrider_SIZE,	//sampleindex. if at end of sample array sound is not playing
	40,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Synthrider",	// sample name

	Tackr,	// pointer to sample array
	Tackr_SIZE,	// size of the sample array
	Tackr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	41,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tackr",	// sample name

	Tcrashhitr,	// pointer to sample array
	Tcrashhitr_SIZE,	// size of the sample array
	Tcrashhitr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	42,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tcrashhitr",	// sample name

	Tom2r,	// pointer to sample array
	Tom2r_SIZE,	// size of the sample array
	Tom2r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	43,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tom2r",	// sample name

	Wsaclapr,	// pointer to sample array
	Wsaclapr_SIZE,	// size of the sample array
	Wsaclapr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	44,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsaclapr",	// sample name

	Wsaclhh1r,	// pointer to sample array
	Wsaclhh1r_SIZE,	// size of the sample array
	Wsaclhh1r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	45,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsaclhh1r",	// sample name

	Wsakick4r,	// pointer to sample array
	Wsakick4r_SIZE,	// size of the sample array
	Wsakick4r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	46,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsakick4r",	// sample name

	Wsakick5r,	// pointer to sample array
	Wsakick5r_SIZE,	// size of the sample array
	Wsakick5r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	47,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsakick5r",	// sample name

	Wsakick6r,	// pointer to sample array
	Wsakick6r_SIZE,	// size of the sample array
	Wsakick6r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	48,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsakick6r",	// sample name

	Wsakick7r,	// pointer to sample array
	Wsakick7r_SIZE,	// size of the sample array
	Wsakick7r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	49,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsakick7r",	// sample name

	Wsaopenhh1r,	// pointer to sample array
	Wsaopenhh1r_SIZE,	// size of the sample array
	Wsaopenhh1r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	50,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsaopenhh1r",	// sample name

	Wsaride1r,	// pointer to sample array
	Wsaride1r_SIZE,	// size of the sample array
	Wsaride1r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	51,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsaride1r",	// sample name

	Wsaride2r,	// pointer to sample array
	Wsaride2r_SIZE,	// size of the sample array
	Wsaride2r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	52,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsaride2r",	// sample name

	Wsaride3r,	// pointer to sample array
	Wsaride3r_SIZE,	// size of the sample array
	Wsaride3r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	53,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsaride3r",	// sample name

	Wsasd1r,	// pointer to sample array
	Wsasd1r_SIZE,	// size of the sample array
	Wsasd1r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	54,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsasd1r",	// sample name

	Wsasd2r,	// pointer to sample array
	Wsasd2r_SIZE,	// size of the sample array
	Wsasd2r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	55,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsasd2r",	// sample name

	Wsasd3r,	// pointer to sample array
	Wsasd3r_SIZE,	// size of the sample array
	Wsasd3r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	56,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsasd3r",	// sample name

	Wsasd4r,	// pointer to sample array
	Wsasd4r_SIZE,	// size of the sample array
	Wsasd4r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	57,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsasd4r",	// sample name

	Wsasd5r,	// pointer to sample array
	Wsasd5r_SIZE,	// size of the sample array
	Wsasd5r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	58,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsasd5r",	// sample name

	Wsasd6r,	// pointer to sample array
	Wsasd6r_SIZE,	// size of the sample array
	Wsasd6r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	59,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Wsasd6r",	// sample name

};
