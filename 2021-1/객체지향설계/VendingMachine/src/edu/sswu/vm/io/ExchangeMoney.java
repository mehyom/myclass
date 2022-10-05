package edu.sswu.vm.io;

import java.util.List;
import java.util.stream.Collectors;

import edu.sswu.vm.Money;

abstract public class ExchangeMoney<T extends Money> {
	protected String notifyMessage(List<? extends Money> moneyList) {
		return moneyList.stream()
			.map(money -> String.format(" [%d] %s", money.getId(), money.getName() ))
			.collect(Collectors.joining(" / "));
	}	
	abstract public void displayInputMessage();
	abstract public void input(T money);
}
