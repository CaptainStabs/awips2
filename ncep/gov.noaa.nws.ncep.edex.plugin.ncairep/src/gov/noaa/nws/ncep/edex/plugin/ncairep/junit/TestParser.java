package gov.noaa.nws.ncep.edex.plugin.ncairep.junit;

import com.raytheon.uf.edex.wmo.message.WMOHeader;
import gov.noaa.nws.ncep.edex.plugin.ncairep.decoder.NcAirepParser;

public class TestParser {
	WMOHeader wmoHeader;
	String anObservation = "ARP UAL556 4126N 09338W 2359 F370 MS54 220/040KT TB SMTH=";
	public TestParser() {
		NcAirepParser parser = new NcAirepParser(anObservation);
		String turb = parser.getTurbInten();
		System.out.println("turb"+turb);
	}
}
