package edu.sswu.vm;

public class Bill extends Money {
	String serialNumber;
	public Bill(int id, String name, int faceValue, String serialNumber) {
		super(id, name, faceValue);
		this.serialNumber = serialNumber;
	}
	@Override
	public int realValue() {
		return faceValue;
	}
	public String getSerialNumber() {
		return serialNumber;
	}
}
