-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 25, 2025 at 11:49 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `batchd`
--

-- --------------------------------------------------------

--
-- Table structure for table `bookadoption`
--

CREATE TABLE `bookadoption` (
  `book_isbn` int(11) NOT NULL,
  `courseid` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `bookadoption`
--

INSERT INTO `bookadoption` (`book_isbn`, `courseid`) VALUES
(1001, 2),
(1001, 5),
(1002, 1),
(1002, 5),
(1003, 3),
(1004, 2),
(1004, 5),
(1005, 1),
(1006, 1),
(1006, 2),
(1007, 2),
(1007, 3),
(1008, 3),
(1009, 4),
(1010, 4);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bookadoption`
-- Constraints for dumped tables
--

--
-- Constraints for table `bookadoption`
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
