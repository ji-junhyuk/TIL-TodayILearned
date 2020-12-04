package spring.YHBasic.service;

import spring.YHBasic.discount.DiscountPolicy;
import spring.YHBasic.discount.FixDiscountPolicy;
import spring.YHBasic.domain.Member;
import spring.YHBasic.domain.Order;
import spring.YHBasic.repository.MemberRepository;
import spring.YHBasic.repository.MemoryMemberRepository;

public class OrderServiceImpl implements OrderService {

    private final MemberRepository memberRepository;
    private final DiscountPolicy discountPolicy;

    public OrderServiceImpl(MemberRepository memberRepository, DiscountPolicy discountPolicy) {
        this.memberRepository = memberRepository;
        this.discountPolicy = discountPolicy;
    }

    @Override
    public Order createOrder(Long memberId, String itemName, int itemPrice) {

        Member member = memberRepository.findById(memberId);
        int discountPrice = discountPolicy.discount(member, itemPrice);

        return new Order(memberId, itemName, itemPrice, discountPrice);
    }
}
