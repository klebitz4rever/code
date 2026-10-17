<?php

class Timing_Dimension{
    private $_w_limit;
    private $m_maximum;

    public function __construct(){
        $this->_w_limit = 5;
        $this->m_maximum = 100;
    }
    public function implement_limit($i_timing){
        if($i_timing < $this->_w_limit){
            return $this->_w_limit;
        }else if ($i_timing > $this->m_maximum){
            return $this->m_maximum;
        }else{
            return $i_timing;
        }
    }

    public function get_optimized_time($i_terminal_time){
        $l_half_terminal_time = $i_terminal_time / 2;
        $l_optimized_time = $this->implement_limit($l_half_terminal_time);

        return $l_optimized_time;
    }
}