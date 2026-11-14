/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: busseven <busseven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 16:04:47 by busseven          #+#    #+#             */
/*   Updated: 2026/11/05 16:22:32 by busseven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stack>
#include <string>

bool is_operator(const std::string &tok)
{
    return (tok.size() == 1 && (tok[0] == '+' || tok[0] == '-'
            || tok[0] == '*' || tok[0] == '/'));
}

bool compute(const std::string &expr, long &result)
{
    std::stack<long>    st;
    std::istringstream  iss(expr);
    std::string         tok;

    while (iss >> tok)
    {
        if (tok.size() == 1 && tok[0] >= '0' && tok[0] <= '9')
            st.push(tok[0] - '0');
        else if (is_operator(tok))
        {
            if (st.size() < 2)
                return (false);
            long b = st.top();
            st.pop();
            long a = st.top();
            st.pop();
            if (tok[0] == '+')
                st.push(a + b);
            else if (tok[0] == '-')
                st.push(a - b);
            else if (tok[0] == '*')
                st.push(a * b);
            else
            {
                if (b == 0)
                    return (false);
                st.push(a / b);
            }
        }
        else
            return (false);
    }
    if (st.size() != 1)
        return (false);
    result = st.top();
    return (true);
}