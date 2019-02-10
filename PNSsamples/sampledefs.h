// sample structure built by wav2header based on wav2sketch by Paul Stoffregen

struct sample_t {
  const int16_t * samplearray; // pointer to sample array
  uint32_t samplesize; // size of the sample array
  uint32_t sampleindex; // current sample array index when playing. index at last sample= not playing
  uint8_t MIDINOTE;  // MIDI note on that plays this sample
  uint8_t play_volume; // play volume 0-127
  char sname[20];        // sample name
} sample[] = {

	Xgsurdo_m,	// pointer to sample array
	Xgsurdo_m_SIZE,	// size of the sample array
	Xgsurdo_m_SIZE,	//sampleindex. if at end of sample array sound is not playing
	35,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Xgsurdo_m",	// sample name

	Xgsurdo_o,	// pointer to sample array
	Xgsurdo_o_SIZE,	// size of the sample array
	Xgsurdo_o_SIZE,	//sampleindex. if at end of sample array sound is not playing
	36,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Xgsurdo_o",	// sample name

	Castanet1,	// pointer to sample array
	Castanet1_SIZE,	// size of the sample array
	Castanet1_SIZE,	//sampleindex. if at end of sample array sound is not playing
	37,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Castanet1",	// sample name

	Soft_kick1,	// pointer to sample array
	Soft_kick1_SIZE,	// size of the sample array
	Soft_kick1_SIZE,	//sampleindex. if at end of sample array sound is not playing
	38,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Soft_kick1",	// sample name

	Dryhrdsn,	// pointer to sample array
	Dryhrdsn_SIZE,	// size of the sample array
	Dryhrdsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	39,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Dryhrdsn",	// sample name

	Dryrolsn,	// pointer to sample array
	Dryrolsn_SIZE,	// size of the sample array
	Dryrolsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	40,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Dryrolsn",	// sample name

	Drysftsn,	// pointer to sample array
	Drysftsn_SIZE,	// size of the sample array
	Drysftsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	41,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Drysftsn",	// sample name

	Dryfatflmsn,	// pointer to sample array
	Dryfatflmsn_SIZE,	// size of the sample array
	Dryfatflmsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	42,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Dryfatflmsn",	// sample name

	Dryfathrdsn,	// pointer to sample array
	Dryfathrdsn_SIZE,	// size of the sample array
	Dryfathrdsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	43,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Dryfathrdsn",	// sample name

	Dryfatrolsn,	// pointer to sample array
	Dryfatrolsn_SIZE,	// size of the sample array
	Dryfatrolsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	44,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Dryfatrolsn",	// sample name

	Dryfatsftsn,	// pointer to sample array
	Dryfatsftsn_SIZE,	// size of the sample array
	Dryfatsftsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	45,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Dryfatsftsn",	// sample name

	Slmdrysftsn,	// pointer to sample array
	Slmdrysftsn_SIZE,	// size of the sample array
	Slmdrysftsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	46,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Slmdrysftsn",	// sample name

	Dryflmsn,	// pointer to sample array
	Dryflmsn_SIZE,	// size of the sample array
	Dryflmsn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	47,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Dryflmsn",	// sample name

	Mp_sfttm,	// pointer to sample array
	Mp_sfttm_SIZE,	// size of the sample array
	Mp_sfttm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	48,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mp_sfttm",	// sample name

	Softlotom,	// pointer to sample array
	Softlotom_SIZE,	// size of the sample array
	Softlotom_SIZE,	//sampleindex. if at end of sample array sound is not playing
	49,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Softlotom",	// sample name

	Hatcls1,	// pointer to sample array
	Hatcls1_SIZE,	// size of the sample array
	Hatcls1_SIZE,	//sampleindex. if at end of sample array sound is not playing
	50,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hatcls1",	// sample name

	Hatcls2,	// pointer to sample array
	Hatcls2_SIZE,	// size of the sample array
	Hatcls2_SIZE,	//sampleindex. if at end of sample array sound is not playing
	51,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hatcls2",	// sample name

	Mp_hrdtm,	// pointer to sample array
	Mp_hrdtm_SIZE,	// size of the sample array
	Mp_hrdtm_SIZE,	//sampleindex. if at end of sample array sound is not playing
	52,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mp_hrdtm",	// sample name

	Hathlf1,	// pointer to sample array
	Hathlf1_SIZE,	// size of the sample array
	Hathlf1_SIZE,	//sampleindex. if at end of sample array sound is not playing
	53,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hathlf1",	// sample name

	Hathlf2,	// pointer to sample array
	Hathlf2_SIZE,	// size of the sample array
	Hathlf2_SIZE,	//sampleindex. if at end of sample array sound is not playing
	54,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hathlf2",	// sample name

	Hatpdl,	// pointer to sample array
	Hatpdl_SIZE,	// size of the sample array
	Hatpdl_SIZE,	//sampleindex. if at end of sample array sound is not playing
	55,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hatpdl",	// sample name

	Hatpdlt,	// pointer to sample array
	Hatpdlt_SIZE,	// size of the sample array
	Hatpdlt_SIZE,	//sampleindex. if at end of sample array sound is not playing
	56,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hatpdlt",	// sample name

	Mp_sfttmt,	// pointer to sample array
	Mp_sfttmt_SIZE,	// size of the sample array
	Mp_sfttmt_SIZE,	//sampleindex. if at end of sample array sound is not playing
	57,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mp_sfttmt",	// sample name

	Hatopn1,	// pointer to sample array
	Hatopn1_SIZE,	// size of the sample array
	Hatopn1_SIZE,	//sampleindex. if at end of sample array sound is not playing
	58,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Hatopn1",	// sample name

	Mp_hrdtmt,	// pointer to sample array
	Mp_hrdtmt_SIZE,	// size of the sample array
	Mp_hrdtmt_SIZE,	//sampleindex. if at end of sample array sound is not playing
	59,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Mp_hrdtmt",	// sample name

	Softhitom,	// pointer to sample array
	Softhitom_SIZE,	// size of the sample array
	Softhitom_SIZE,	//sampleindex. if at end of sample array sound is not playing
	60,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Softhitom",	// sample name

	Lngridebell,	// pointer to sample array
	Lngridebell_SIZE,	// size of the sample array
	Lngridebell_SIZE,	//sampleindex. if at end of sample array sound is not playing
	61,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lngridebell",	// sample name

	Tambrn1,	// pointer to sample array
	Tambrn1_SIZE,	// size of the sample array
	Tambrn1_SIZE,	//sampleindex. if at end of sample array sound is not playing
	62,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tambrn1",	// sample name

	Tambrn2,	// pointer to sample array
	Tambrn2_SIZE,	// size of the sample array
	Tambrn2_SIZE,	//sampleindex. if at end of sample array sound is not playing
	63,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tambrn2",	// sample name

	Tambrn_pp,	// pointer to sample array
	Tambrn_pp_SIZE,	// size of the sample array
	Tambrn_pp_SIZE,	//sampleindex. if at end of sample array sound is not playing
	64,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tambrn_pp",	// sample name

	Tambrn3,	// pointer to sample array
	Tambrn3_SIZE,	// size of the sample array
	Tambrn3_SIZE,	//sampleindex. if at end of sample array sound is not playing
	65,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Tambrn3",	// sample name

	Cowbell,	// pointer to sample array
	Cowbell_SIZE,	// size of the sample array
	Cowbell_SIZE,	//sampleindex. if at end of sample array sound is not playing
	66,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cowbell",	// sample name

	Ratloop,	// pointer to sample array
	Ratloop_SIZE,	// size of the sample array
	Ratloop_SIZE,	//sampleindex. if at end of sample array sound is not playing
	67,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Ratloop",	// sample name

	Bongohil,	// pointer to sample array
	Bongohil_SIZE,	// size of the sample array
	Bongohil_SIZE,	//sampleindex. if at end of sample array sound is not playing
	68,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Bongohil",	// sample name

	Bongohir,	// pointer to sample array
	Bongohir_SIZE,	// size of the sample array
	Bongohir_SIZE,	//sampleindex. if at end of sample array sound is not playing
	69,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Bongohir",	// sample name

	Bongolol,	// pointer to sample array
	Bongolol_SIZE,	// size of the sample array
	Bongolol_SIZE,	//sampleindex. if at end of sample array sound is not playing
	70,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Bongolol",	// sample name

	Bongolor,	// pointer to sample array
	Bongolor_SIZE,	// size of the sample array
	Bongolor_SIZE,	//sampleindex. if at end of sample array sound is not playing
	71,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Bongolor",	// sample name

	Cga_slapl,	// pointer to sample array
	Cga_slapl_SIZE,	// size of the sample array
	Cga_slapl_SIZE,	//sampleindex. if at end of sample array sound is not playing
	72,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cga_slapl",	// sample name

	Cga_slapr,	// pointer to sample array
	Cga_slapr_SIZE,	// size of the sample array
	Cga_slapr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	73,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cga_slapr",	// sample name

	Cga_opnhil,	// pointer to sample array
	Cga_opnhil_SIZE,	// size of the sample array
	Cga_opnhil_SIZE,	//sampleindex. if at end of sample array sound is not playing
	74,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cga_opnhil",	// sample name

	Cga_opnhir,	// pointer to sample array
	Cga_opnhir_SIZE,	// size of the sample array
	Cga_opnhir_SIZE,	//sampleindex. if at end of sample array sound is not playing
	75,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cga_opnhir",	// sample name

	Cga_opnlol,	// pointer to sample array
	Cga_opnlol_SIZE,	// size of the sample array
	Cga_opnlol_SIZE,	//sampleindex. if at end of sample array sound is not playing
	76,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cga_opnlol",	// sample name

	Cga_opnlor,	// pointer to sample array
	Cga_opnlor_SIZE,	// size of the sample array
	Cga_opnlor_SIZE,	//sampleindex. if at end of sample array sound is not playing
	77,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cga_opnlor",	// sample name

	Timbale1l,	// pointer to sample array
	Timbale1l_SIZE,	// size of the sample array
	Timbale1l_SIZE,	//sampleindex. if at end of sample array sound is not playing
	78,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Timbale1l",	// sample name

	Timbale1r,	// pointer to sample array
	Timbale1r_SIZE,	// size of the sample array
	Timbale1r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	79,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Timbale1r",	// sample name

	Timbale2l,	// pointer to sample array
	Timbale2l_SIZE,	// size of the sample array
	Timbale2l_SIZE,	//sampleindex. if at end of sample array sound is not playing
	80,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Timbale2l",	// sample name

	Timbale2r,	// pointer to sample array
	Timbale2r_SIZE,	// size of the sample array
	Timbale2r_SIZE,	//sampleindex. if at end of sample array sound is not playing
	81,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Timbale2r",	// sample name

	Agoggohil,	// pointer to sample array
	Agoggohil_SIZE,	// size of the sample array
	Agoggohil_SIZE,	//sampleindex. if at end of sample array sound is not playing
	82,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Agoggohil",	// sample name

	Agoggohir,	// pointer to sample array
	Agoggohir_SIZE,	// size of the sample array
	Agoggohir_SIZE,	//sampleindex. if at end of sample array sound is not playing
	83,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Agoggohir",	// sample name

	Agoogolol,	// pointer to sample array
	Agoogolol_SIZE,	// size of the sample array
	Agoogolol_SIZE,	//sampleindex. if at end of sample array sound is not playing
	84,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Agoogolol",	// sample name

	Agoogolor,	// pointer to sample array
	Agoogolor_SIZE,	// size of the sample array
	Agoogolor_SIZE,	//sampleindex. if at end of sample array sound is not playing
	85,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Agoogolor",	// sample name

	Cabasa_upl,	// pointer to sample array
	Cabasa_upl_SIZE,	// size of the sample array
	Cabasa_upl_SIZE,	//sampleindex. if at end of sample array sound is not playing
	86,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cabasa_upl",	// sample name

	Cabasa_upr,	// pointer to sample array
	Cabasa_upr_SIZE,	// size of the sample array
	Cabasa_upr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	87,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cabasa_upr",	// sample name

	Maracasl,	// pointer to sample array
	Maracasl_SIZE,	// size of the sample array
	Maracasl_SIZE,	//sampleindex. if at end of sample array sound is not playing
	88,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Maracasl",	// sample name

	Maracasr,	// pointer to sample array
	Maracasr_SIZE,	// size of the sample array
	Maracasr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	89,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Maracasr",	// sample name

	Cabasa_outl,	// pointer to sample array
	Cabasa_outl_SIZE,	// size of the sample array
	Cabasa_outl_SIZE,	//sampleindex. if at end of sample array sound is not playing
	90,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cabasa_outl",	// sample name

	Cabasa_outr,	// pointer to sample array
	Cabasa_outr_SIZE,	// size of the sample array
	Cabasa_outr_SIZE,	//sampleindex. if at end of sample array sound is not playing
	91,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cabasa_outr",	// sample name

	Shortwhistle,	// pointer to sample array
	Shortwhistle_SIZE,	// size of the sample array
	Shortwhistle_SIZE,	//sampleindex. if at end of sample array sound is not playing
	92,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Shortwhistle",	// sample name

	Longwhistle,	// pointer to sample array
	Longwhistle_SIZE,	// size of the sample array
	Longwhistle_SIZE,	//sampleindex. if at end of sample array sound is not playing
	93,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Longwhistle",	// sample name

	Shrt_guiro,	// pointer to sample array
	Shrt_guiro_SIZE,	// size of the sample array
	Shrt_guiro_SIZE,	//sampleindex. if at end of sample array sound is not playing
	94,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Shrt_guiro",	// sample name

	Lng_guiro2,	// pointer to sample array
	Lng_guiro2_SIZE,	// size of the sample array
	Lng_guiro2_SIZE,	//sampleindex. if at end of sample array sound is not playing
	95,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Lng_guiro2",	// sample name

	Claves2,	// pointer to sample array
	Claves2_SIZE,	// size of the sample array
	Claves2_SIZE,	//sampleindex. if at end of sample array sound is not playing
	96,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Claves2",	// sample name

	Woodblock,	// pointer to sample array
	Woodblock_SIZE,	// size of the sample array
	Woodblock_SIZE,	//sampleindex. if at end of sample array sound is not playing
	97,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Woodblock",	// sample name

	Cuica,	// pointer to sample array
	Cuica_SIZE,	// size of the sample array
	Cuica_SIZE,	//sampleindex. if at end of sample array sound is not playing
	98,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Cuica",	// sample name

	Triangl_opn,	// pointer to sample array
	Triangl_opn_SIZE,	// size of the sample array
	Triangl_opn_SIZE,	//sampleindex. if at end of sample array sound is not playing
	99,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Triangl_opn",	// sample name

	Shaker1,	// pointer to sample array
	Shaker1_SIZE,	// size of the sample array
	Shaker1_SIZE,	//sampleindex. if at end of sample array sound is not playing
	100,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Shaker1",	// sample name

	Shaker2,	// pointer to sample array
	Shaker2_SIZE,	// size of the sample array
	Shaker2_SIZE,	//sampleindex. if at end of sample array sound is not playing
	101,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Shaker2",	// sample name

	Shaker3,	// pointer to sample array
	Shaker3_SIZE,	// size of the sample array
	Shaker3_SIZE,	//sampleindex. if at end of sample array sound is not playing
	102,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Shaker3",	// sample name

	Xgjinglebell,	// pointer to sample array
	Xgjinglebell_SIZE,	// size of the sample array
	Xgjinglebell_SIZE,	//sampleindex. if at end of sample array sound is not playing
	103,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"Xgjinglebell",	// sample name

	_belltree,	// pointer to sample array
	_belltree_SIZE,	// size of the sample array
	_belltree_SIZE,	//sampleindex. if at end of sample array sound is not playing
	104,	// MIDI note on that plays this sample
	127,	// play volume 0-127
	"_belltree",	// sample name

};
