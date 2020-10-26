package jpabook.jpashop.service;

import jpabook.jpashop.domain.Delivery;
import jpabook.jpashop.domain.Member;
import jpabook.jpashop.domain.Order;
import jpabook.jpashop.domain.OrderItem;
import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.repository.ItemRepository;
import jpabook.jpashop.repository.MemberRepository;
import jpabook.jpashop.repository.OrderRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class OrderService {

    private final OrderRepository orderRepository;
    private final MemberRepository memberRepository;
    private final ItemRepository itemRepository;
    /*
    Order
     */
    @Transactional
    public Long order(Long memberId, Long itemId, int count) {

        //lookup entity
        Member member = memberRepository.findOne(memberId);
        Item item = itemRepository.findOne(itemId);

        //create delivery information
        Delivery delivery = new Delivery();
        delivery.setAddress(member.getAddress());

        //create OrderItem
        OrderItem orderItem = OrderItem.createOrderItem(item, item.getPrice(), count);

        //create order
        Order order = Order.createOrder(member, delivery, orderItem);

        //store order
        orderRepository.save(order);

        return order.getId();
    }

    /*
    cancel order
     */
    @Transactional
    public void cancelOrder(Long orderId) {

        //lookup order entity
        Order order = orderRepository.findOne(orderId);
        //cancel order
        order.cancel();
    }


    //search
//    public List<Order> findOrders(OrderSearch orderSearch) {
//        return orderRepository.findAll(orderSearch)
//    }
}
